#include "application.hpp"

#include <unistd.h>
#include <signal.h>

#include "src/tcp_server.hpp"
#include "src/daemon.hpp"
#include "src/config.hpp"
#include "src/env.hpp"
#include "src/log.hpp"
#include "src/module.hpp"
//#include "src/rock/rock_stream.h"
//#include "src/worker.h"
//#include "src/http/ws_server.h"
//#include "src/rock/rock_server.h"
//#include "src/ns/name_server_module.h"
//#include "src/db/fox_thread.h"
//#include "src/db/redis.h"

namespace stone {

static stone::Logger::ptr g_logger = STONE_LOG_NAME("system");

static stone::ConfigVar<std::string>::ptr g_server_work_path =
    stone::Config::Lookup("server.work_path"
            ,std::string("/apps/work/stone")
            , "server work path");

static stone::ConfigVar<std::string>::ptr g_server_pid_file =
    stone::Config::Lookup("server.pid_file"
            ,std::string("stone.pid")
            , "server pid file");

static stone::ConfigVar<std::string>::ptr g_service_discovery_zk =
    stone::Config::Lookup("service_discovery.zk"
            ,std::string("")
            , "service discovery zookeeper");


static stone::ConfigVar<std::vector<TcpServerConf> >::ptr g_servers_conf
    = stone::Config::Lookup("servers", std::vector<TcpServerConf>(), "http server config");

Application* Application::s_instance = nullptr;

Application::Application() {
    s_instance = this;
}

bool Application::init(int argc, char** argv) {
    m_argc = argc;
    m_argv = argv;

    stone::EnvMgr::GetInstance()->addHelp("s", "start with the terminal");
    stone::EnvMgr::GetInstance()->addHelp("d", "run as daemon");
    stone::EnvMgr::GetInstance()->addHelp("c", "conf path default: ./conf");
    stone::EnvMgr::GetInstance()->addHelp("p", "print help");

    bool is_print_help = false;
    if(!stone::EnvMgr::GetInstance()->init(argc, argv)) {
        is_print_help = true;
    }

    if(stone::EnvMgr::GetInstance()->has("p")) {
        is_print_help = true;
    }

    std::string conf_path = stone::EnvMgr::GetInstance()->getConfigPath();
    STONE_LOG_INFO(g_logger) << "load conf path:" << conf_path;
    stone::Config::LoadFromConfDir(conf_path);

    ModuleMgr::GetInstance()->init();
    std::vector<Module::ptr> modules;
    ModuleMgr::GetInstance()->listAll(modules);

    for(auto i : modules) {
        i->onBeforeArgsParse(argc, argv);
    }

    if(is_print_help) {
        stone::EnvMgr::GetInstance()->printHelp();
        return false;
    }

    for(auto i : modules) {
        i->onAfterArgsParse(argc, argv);
    }
    modules.clear();

    int run_type = 0;
    if(stone::EnvMgr::GetInstance()->has("s")) {
        run_type = 1;
    }
    if(stone::EnvMgr::GetInstance()->has("d")) {
        run_type = 2;
    }

    if(run_type == 0) {
        stone::EnvMgr::GetInstance()->printHelp();
        return false;
    }

    std::string pidfile = g_server_work_path->getValue()
                                + "/" + g_server_pid_file->getValue();
    if(stone::FSUtil::IsRunningPidfile(pidfile)) {
        STONE_LOG_ERROR(g_logger) << "server is running:" << pidfile;
        return false;
    }

    if(!stone::FSUtil::Mkdir(g_server_work_path->getValue())) {
        STONE_LOG_FATAL(g_logger) << "create work path [" << g_server_work_path->getValue()
            << " errno=" << errno << " errstr=" << strerror(errno);
        return false;
    }
    return true;
}

bool Application::run() {
    bool is_daemon = stone::EnvMgr::GetInstance()->has("d");
    return start_daemon(m_argc, m_argv,
            std::bind(&Application::main, this, std::placeholders::_1,
                std::placeholders::_2), is_daemon);
}

int Application::main(int argc, char** argv) {
    signal(SIGPIPE, SIG_IGN);
    STONE_LOG_INFO(g_logger) << "main";
    std::string conf_path = stone::EnvMgr::GetInstance()->getConfigPath();
    stone::Config::LoadFromConfDir(conf_path, true);
    {
        std::string pidfile = g_server_work_path->getValue()
                                    + "/" + g_server_pid_file->getValue();
        std::ofstream ofs(pidfile);
        if(!ofs) {
            STONE_LOG_ERROR(g_logger) << "open pidfile " << pidfile << " failed";
            return false;
        }
        ofs << getpid();
    }

    m_mainIOManager.reset(new stone::IOManager(1, true, "main"));
    m_mainIOManager->schedule(std::bind(&Application::run_fiber, this));
    m_mainIOManager->addTimer(2000, [](){
            //STONE_LOG_INFO(g_logger) << "hello";
    }, true);
    m_mainIOManager->stop();
    return 0;
}

int Application::run_fiber() {
    std::vector<Module::ptr> modules;
    ModuleMgr::GetInstance()->listAll(modules);
    bool has_error = false;
    for(auto& i : modules) {
        if(!i->onLoad()) {
            STONE_LOG_ERROR(g_logger) << "module name="
                << i->getName() << " version=" << i->getVersion()
                << " filename=" << i->getFileName();
            has_error = true;
        }
    }
    if(has_error) {
        _exit(0);
    }

    //stone::WorkerMgr::GetInstance()->init();
    //FoxThreadMgr::GetInstance()->init();
    //FoxThreadMgr::GetInstance()->start();
    //RedisMgr::GetInstance();

    auto http_confs = g_servers_conf->getValue();
    std::vector<TcpServer::ptr> svrs;
    for(auto& i : http_confs) {
        STONE_LOG_DEBUG(g_logger) << std::endl << LexicalCast<TcpServerConf, std::string>()(i);

        std::vector<Address::ptr> address;
        for(auto& a : i.address) {
            size_t pos = a.find(":");
            if(pos == std::string::npos) {
                //STONE_LOG_ERROR(g_logger) << "invalid address: " << a;
                address.push_back(UnixAddress::ptr(new UnixAddress(a)));
                continue;
            }
            int32_t port = atoi(a.substr(pos + 1).c_str());
            //127.0.0.1
            auto addr = stone::IPAddress::Create(a.substr(0, pos).c_str(), port);
            if(addr) {
                address.push_back(addr);
                continue;
            }
            std::vector<std::pair<Address::ptr, uint32_t> > result;
            if(stone::Address::GetInterfaceAddresses(result,
                                        a.substr(0, pos))) {
                for(auto& x : result) {
                    auto ipaddr = std::dynamic_pointer_cast<IPAddress>(x.first);
                    if(ipaddr) {
                        ipaddr->setPort(atoi(a.substr(pos + 1).c_str()));
                    }
                    address.push_back(ipaddr);
                }
                continue;
            }

            auto aaddr = stone::Address::LookupAny(a);
            if(aaddr) {
                address.push_back(aaddr);
                continue;
            }
            STONE_LOG_ERROR(g_logger) << "invalid address: " << a;
            _exit(0);
        }
        IOManager* accept_worker = stone::IOManager::GetThis();
        IOManager* io_worker = stone::IOManager::GetThis();
        IOManager* process_worker = stone::IOManager::GetThis();
        if(!i.accept_worker.empty()) {
            accept_worker = stone::IOManager::GetThis();//stone::WorkerMgr::GetInstance()->getAsIOManager(i.accept_worker).get();
            if(!accept_worker) {
                STONE_LOG_ERROR(g_logger) << "accept_worker: " << i.accept_worker
                    << " not exists";
                _exit(0);
            }
        }
        if(!i.io_worker.empty()) {
            io_worker =stone::IOManager::GetThis(); //stone::WorkerMgr::GetInstance()->getAsIOManager(i.io_worker).get();
            if(!io_worker) {
                STONE_LOG_ERROR(g_logger) << "io_worker: " << i.io_worker
                    << " not exists";
                _exit(0);
            }
        }
        if(!i.process_worker.empty()) {
            process_worker = stone::IOManager::GetThis();//stone::WorkerMgr::GetInstance()->getAsIOManager(i.process_worker).get();
            if(!process_worker) {
                STONE_LOG_ERROR(g_logger) << "process_worker: " << i.process_worker
                    << " not exists";
                _exit(0);
            }
        }

        TcpServer::ptr server;
        if(i.type == "http") {
            server.reset(new stone::http::HttpServer(i.keepalive,
                            process_worker, io_worker, accept_worker));
        }/* else if(i.type == "ws") {
            server.reset(new stone::http::WSServer(
                            process_worker, io_worker, accept_worker));
        } else if(i.type == "rock") {
            server.reset(new stone::RockServer("rock",
                            process_worker, io_worker, accept_worker));
        } else if(i.type == "nameserver") {
            server.reset(new stone::RockServer("nameserver",
                            process_worker, io_worker, accept_worker));
            ModuleMgr::GetInstance()->add(std::make_shared<stone::ns::NameServerModule>());
        }*/ else {
            STONE_LOG_ERROR(g_logger) << "invalid server type=" << i.type
                << LexicalCast<TcpServerConf, std::string>()(i);
            _exit(0);
        }
        if(!i.name.empty()) {
            server->setName(i.name);
        }
        std::vector<Address::ptr> fails;
        if(!server->bind(address, fails, i.ssl)) {
            for(auto& x : fails) {
                STONE_LOG_ERROR(g_logger) << "bind address fail:"
                    << *x;
            }
            _exit(0);
        }
        //if(i.ssl) {
        //    if(!server->loadCertificates(i.cert_file, i.key_file)) {
        //        STONE_LOG_ERROR(g_logger) << "loadCertificates fail, cert_file="
        //            << i.cert_file << " key_file=" << i.key_file;
        //    }
        //}
        server->setConf(i);
        //server->start();
        m_servers[i.type].push_back(server);
        svrs.push_back(server);
    }

    /*if(!g_service_discovery_zk->getValue().empty()) {
    //    m_serviceDiscovery.reset(new ZKServiceDiscovery(g_service_discovery_zk->getValue()));
     //   m_rockSDLoadBalance.reset(new RockSDLoadBalance(m_serviceDiscovery));

        std::vector<TcpServer::ptr> svrs;
        if(!getServer("http", svrs)) {
            m_serviceDiscovery->setSelfInfo(stone::GetIPv4() + ":0:" + stone::GetHostName());
        } else {
            std::string ip_and_port;
            for(auto& i : svrs) {
                auto socks = i->getSocks();
                for(auto& s : socks) {
                    auto addr = std::dynamic_pointer_cast<IPv4Address>(s->getLocalAddress());
                    if(!addr) {
                        continue;
                    }
                    auto str = addr->toString();
                    if(str.find("127.0.0.1") == 0) {
                        continue;
                    }
                    if(str.find("0.0.0.0") == 0) {
                        ip_and_port = stone::GetIPv4() + ":" + std::to_string(addr->getPort());
                        break;
                    } else {
                        ip_and_port = addr->toString();
                    }
                }
                if(!ip_and_port.empty()) {
                    break;
                }
            }
            m_serviceDiscovery->setSelfInfo(ip_and_port + ":" + stone::GetHostName());
        }
    }*/

    for(auto& i : modules) {
        i->onServerReady();
    }

    for(auto& i : svrs) {
        i->start();
    }

    /*if(m_rockSDLoadBalance) {
        m_rockSDLoadBalance->start();
    }*/

    for(auto& i : modules) {
        i->onServerUp();
    }
    //ZKServiceDiscovery::ptr m_serviceDiscovery;
    //RockSDLoadBalance::ptr m_rockSDLoadBalance;
    //stone::ZKServiceDiscovery::ptr zksd(new stone::ZKServiceDiscovery("127.0.0.1:21811"));
    //zksd->registerServer("blog", "chat", stone::GetIPv4() + ":8090", "xxx");
    //zksd->queryServer("blog", "chat");
    //zksd->setSelfInfo(stone::GetIPv4() + ":8090");
    //zksd->setSelfData("vvv");
    //static RockSDLoadBalance::ptr rsdlb(new RockSDLoadBalance(zksd));
    //rsdlb->start();
    return 0;
}

bool Application::getServer(const std::string& type, std::vector<TcpServer::ptr>& svrs) {
    auto it = m_servers.find(type);
    if(it == m_servers.end()) {
        return false;
    }
    svrs = it->second;
    return true;
}

void Application::listAllServer(std::map<std::string, std::vector<TcpServer::ptr> >& servers) {
    servers = m_servers;
}

}

//#include "application.hpp"
//#include "log.hpp"
//#include "config.hpp"
//#include "env.hpp"
//#include "daemon.hpp"
//#include "address.hpp"
//#include "module.hpp"
//#include "tcp_server.hpp"
//
//namespace stone{
//
//static stone::Logger::ptr g_logger = STONE_LOG_NAME("system");
//
//static stone::ConfigVar<std::string>::ptr g_server_work_path = 
//                stone::Config::Lookup("server.work_path"
//                                    ,std::string("/apps/work/stone")
//                                    ,"server work path");
//
//static stone::ConfigVar<std::string>::ptr g_server_pid_file = 
//                stone::Config::Lookup("server.pid_file"
//                                    ,std::string("server.pid")
//                                    ,"server pid file");
//
//struct HttpServerConf{
//    std::vector<std::string> address;
//    int keepalive = 0;
//    int timeout = 60 * 2 * 1000;
//    std::string name;
//
//    bool isValid() const {
//        return !address.empty();
//    }
//    bool operator==(const HttpServerConf& rhs) const{
//        return address == rhs.address
//            && keepalive == rhs.keepalive
//            && timeout == rhs.timeout
//            && name == rhs.name;
//    }
//};
//
//template<>
//class LexicalCast<std::string,HttpServerConf>{
//public:
//    HttpServerConf operator()(const std::string& v){
//        YAML::Node node = YAML::Load(v);
//        HttpServerConf conf;
//        conf.keepalive = node["keepalive"].as<int>(conf.keepalive);
//        conf.timeout = node["timeout"].as<int>(conf.timeout);
//        conf.name = node["name"].as<std::string>(conf.name);
//
//        if(node["address"].IsDefined()){
//            for(size_t i = 0;i < node["address"].size();++i){
//                conf.address.push_back(node["address"][i].as<std::string>());
//            }
//        }
//        return conf;
//    }
//};
//
//template<>
//class LexicalCast<HttpServerConf,std::string>{
//public:
//    std::string operator()(const HttpServerConf& conf){
//        YAML::Node node;
//        node["name"] = conf.name;
//        node["keepalive"] = conf.keepalive;
//        node["timeout"] = conf.timeout;
//        for(auto& i : conf.address){
//            node["address"].push_back(i);
//        }
//        std::stringstream ss;
//        ss << node;
//        return ss.str();
//    }
//};
//static stone::ConfigVar<std::vector<HttpServerConf> >::ptr g_http_servers_conf = 
//                stone::Config::Lookup("http_servers"
//                                    ,std::vector<HttpServerConf>()
//                                    ,"http server config");
//Application* Application::s_instance = nullptr;
//Application::Application(){
//    s_instance = this;
//}
//
//bool Application::run(){
//    bool is_daemon = stone::EnvMgr::GetInstance()->has("d");
//    return start_daemon(m_argc,m_argv,std::bind(&Application::main,this,std::placeholders::_1,std::placeholders::_2),is_daemon);
//}
//
//int Application::main(int argc,char** argv){
//    std::string pidFile = g_server_work_path->getValue() +
//                            "/" + g_server_pid_file->getValue();
//    std::ofstream ofs(pidFile);
//    if(!ofs){
//        STONE_LOG_ERROR(g_logger) << "open pidfile " << pidFile <<" failed";
//        return -1;
//    }
//    ofs << getpid();
//
//    m_mainIOManager.reset(new stone::IOManager(1,true,"main"));
//    m_mainIOManager->schedule(std::bind(&Application::run_fiber,this));
//    m_mainIOManager->addTimer(2000,[](){
//    },true);
//    m_mainIOManager->stop();
//    return 0;
//}
//
//int Application::run_fiber(){
//    std::vector<Module::ptr> modules;
//    stone::ModuleMgr::GetInstance()->listAll(modules);
//    auto http_confs = g_http_servers_conf->getValue();
//    for(auto& i : http_confs){
//        STONE_LOG_INFO(g_logger) << LexicalCast<HttpServerConf,std::string>()(i);
//        std::vector<Address::ptr> address;
//        for(auto& a : i.address){
//            size_t pos = a.find(":");
//            if(pos == std::string::npos){
//                STONE_LOG_ERROR(g_logger) << "invalid address: " <<a;
//                continue;
//            }
//            auto addr = stone::Address::LookupAny(a);
//            if(addr){
//                address.push_back(addr);
//                continue;
//            }
//            std::vector<std::pair<Address::ptr,uint32_t> > result;
//            if(stone::Address::GetInterfaceAddresses(result,a.substr(0,pos))){
//                for(auto& x : result){
//                    auto ipaddr = std::dynamic_pointer_cast<IPAddress>(x.first);
//                    if(ipaddr){
//                        ipaddr->setPort(atoi(a.substr(pos + 1).c_str()));
//                    }
//                    address.push_back(ipaddr);
//                }
//                continue;
//            }
//            auto aaddr =stone::Address::LookupAny(a);
//            if(aaddr) {
//                 address.push_back(aaddr);
//                 continue;
//             }
//             STONE_LOG_ERROR(g_logger) << "invalid address: " << a;
//             _exit(0);
//        }
//
//        IOManager* accept_worker = stone::IOManager::GetThis();
//        IOManager* io_worker = stone::IOManager::GetThis();
//        IOManager* process_worker = stone::IOManager::GetThis();
//        //if(!i.accept_worker.empty()) {
//        //    accept_worker = stone::WorkerMgr::GetInstance()->getAsIOManager(i.accept_worker).get();
//        //    if(!accept_worker) {
//        //        STONE_LOG_ERROR(g_logger) << "accept_worker: " << i.accept_worker
//        //            << " not exists";
//        //        _exit(0);
//        //    }
//        //}
//        //if(!i.io_worker.empty()) {
//        //    io_worker = STONE::WorkerMgr::GetInstance()->getAsIOManager(i.io_worker).get();
//        //    if(!io_worker) {
//        //        STONE_LOG_ERROR(g_logger) << "io_worker: " << i.io_worker
//        //            << " not exists";
//        //        _exit(0);
//        //    }
//        //}
//        //if(!i.process_worker.empty()) {
//        //    process_worker = STONE::WorkerMgr::GetInstance()->getAsIOManager(i.process_worker).get();
//        //    if(!process_worker) {
//        //        STONE_LOG_ERROR(g_logger) << "process_worker: " << i.process_worker
//        //            << " not exists";
//        //        _exit(0);
//        //    }
//        //}
//
//
//        stone::TcpServer::ptr server(new stone::http::HttpServer(i.keepalive,process_worker,io_worker,accept_worker));
//
//        std::vector<Address::ptr> fails;
//        if(!server->bind(address,fails)){
//            for(auto& x : address){
//                STONE_LOG_ERROR(g_logger) << "bind address fail: "
//                    <<*x;
//            }
//            exit(0);
//        }
//        server->setName(i.name);
//        server->start();
//
//        m_servers.push_back(server);
//    }
//
//    for(auto& i : modules){
//        i->onServerReady();
//    }
//    return 0;
//}
//
//bool Application::init(int argc,char** argv){
//    m_argc = argc;
//    m_argv = argv;
//    EnvMgr::GetInstance()->addHelp("s","start with the terminal");
//    EnvMgr::GetInstance()->addHelp("d","run as daemon");
//    EnvMgr::GetInstance()->addHelp("c","conf path default: ./conf");
//    EnvMgr::GetInstance()->addHelp("p","print help");
//
//    bool is_print_help = false;
//    if(!EnvMgr::GetInstance()->init(argc,argv)){
//        is_print_help = true;
//    }
//    if(stone::EnvMgr::GetInstance()->has("p")){
//        is_print_help = true;
//    }
//    std::string conf_path = EnvMgr::GetInstance()->getConfigPath();
//    STONE_LOG_INFO(g_logger) << "load conf path:" <<conf_path;
//    stone::Config::LoadFromConfDir(conf_path);
// 
//    ModuleMgr::GetInstance()->init();
//    std::vector<Module::ptr> modules;
//    ModuleMgr::GetInstance()->listAll(modules);
//
//    for(auto& i : modules){
//        i->onBeforeArgsParse(argc,argv);
//    }
//    if(is_print_help){
//        stone::EnvMgr::GetInstance()->printHelp();
//        return false;
//    }
//    for(auto& i : modules){
//        i->onAfterArgsParse(argc,argv);
//    }
//    modules.clear();
//
//    int run_type = 0;
//    if(stone::EnvMgr::GetInstance()->has("d")){
//        run_type = 1;
//    }
//    if(stone::EnvMgr::GetInstance()->has("s")){
//        run_type = 2;
//    }
//    if(run_type == 0){
//        stone::EnvMgr::GetInstance()->printHelp();
//        return false;
//    }
//    std::string pidFile = g_server_work_path->getValue() +
//                            "/" + g_server_pid_file->getValue();
//    if(stone::FSUtil::IsRunningPidfile(pidFile)){
//        STONE_LOG_ERROR(g_logger) << "server is running:" <<pidFile;
//        return false;
//    }
//
//   
//
//    if(!stone::FSUtil::Mkdir(g_server_work_path->getValue())){
//            STONE_LOG_ERROR(g_logger) << "create work path [" << g_server_work_path->getValue()
//            <<" errno=" << errno << " strerror" << strerror(errno);
//            return false;
//    }
//    return true;
//
//}
// 
//bool Application::getServers(const std::string& type,std::vector<TcpServer::ptr>& servers){
//
//    servers = m_servers;
//    return true;
//}
//
//void Application::listAllServers(std::map<std::string,std::vector<TcpServer::ptr> >& servers){
//}
//
//}
