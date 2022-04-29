#include "tcp_server.hpp"
#include "config.hpp"
#include "log.hpp"

namespace stone {

static stone::ConfigVar<uint64_t>::ptr g_tcp_server_read_timeout =
    stone::Config::Lookup("tcp_server.read_timeout", (uint64_t)(60 * 1000 * 2),
            "tcp server read timeout");

static stone::Logger::ptr g_logger = STONE_LOG_NAME("system");

TcpServer::TcpServer(stone::IOManager* worker,
                    stone::IOManager* io_worker,
                    stone::IOManager* accept_worker)
    :m_worker(worker)
    ,m_ioWorker(io_worker)
    ,m_acceptWorker(accept_worker)
    ,m_recvTimeout(g_tcp_server_read_timeout->getValue())
    ,m_name("stone/1.0.0")
    ,m_isStop(true) {
}

TcpServer::~TcpServer() {
    for(auto& i : m_socks) {
        i->close();
    }
    m_socks.clear();
}

void TcpServer::setConf(const TcpServerConf& v) {
    m_conf.reset(new TcpServerConf(v));
}

bool TcpServer::bind(stone::Address::ptr addr, bool ssl) {
    std::vector<Address::ptr> addrs;
    std::vector<Address::ptr> fails;
    addrs.push_back(addr);
    return bind(addrs, fails, ssl);
}

bool TcpServer::bind(const std::vector<Address::ptr>& addrs
                        ,std::vector<Address::ptr>& fails
                        ,bool ssl) {
    m_ssl = ssl;
    for(auto& addr : addrs) {
        Socket::ptr sock = Socket::CreateTCP(addr);//ssl ? SSLSocket::CreateTCP(addr) : Socket::CreateTCP(addr);
        if(!sock->bind(addr)) {
            STONE_LOG_ERROR(g_logger) << "bind fail errno="
                << errno << " errstr=" << strerror(errno)
                << " addr=[" << addr->toString() << "]";
            fails.push_back(addr);
            continue;
        }
        if(!sock->listen()) {
            STONE_LOG_ERROR(g_logger) << "listen fail errno="
                << errno << " errstr=" << strerror(errno)
                << " addr=[" << addr->toString() << "]";
            fails.push_back(addr);
            continue;
        }
        m_socks.push_back(sock);
    }

    if(!fails.empty()) {
        m_socks.clear();
        return false;
    }

    for(auto& i : m_socks) {
        STONE_LOG_INFO(g_logger) << "type=" << m_type
            << " name=" << m_name
            << " ssl=" << m_ssl
            << " server bind success: " << *i;
    }
    return true;
}

void TcpServer::startAccept(Socket::ptr sock) {
    while(!m_isStop) {
        Socket::ptr client = sock->accept();
        if(client) {
            client->setRecvTimeout(m_recvTimeout);
            m_ioWorker->schedule(std::bind(&TcpServer::handleClient,
                        shared_from_this(), client));
        } else {
            STONE_LOG_ERROR(g_logger) << "accept errno=" << errno
                << " errstr=" << strerror(errno);
        }
    }
}

bool TcpServer::start() {
    if(!m_isStop) {
        return true;
    }
    m_isStop = false;
    for(auto& sock : m_socks) {
        m_acceptWorker->schedule(std::bind(&TcpServer::startAccept,
                    shared_from_this(), sock));
    }
    return true;
}

void TcpServer::stop() {
    m_isStop = true;
    auto self = shared_from_this();
    m_acceptWorker->schedule([this, self]() {
        for(auto& sock : m_socks) {
            sock->cancelAll();
            sock->close();
        }
        m_socks.clear();
    });
}

void TcpServer::handleClient(Socket::ptr client) {
    STONE_LOG_INFO(g_logger) << "handleClient: " << *client;
}

//bool TcpServer::loadCertificates(const std::string& cert_file, const std::string& key_file) {
//    for(auto& i : m_socks) {
//        auto ssl_socket = std::dynamic_pointer_cast<SSLSocket>(i);
//        if(ssl_socket) {
//            if(!ssl_socket->loadCertificates(cert_file, key_file)) {
//                return false;
//            }
//        }
//    }
//    return true;
//}

std::string TcpServer::toString(const std::string& prefix) {
    std::stringstream ss;
    ss << prefix << "[type=" << m_type
       << " name=" << m_name << " ssl=" << m_ssl
       << " worker=" << (m_worker ? m_worker->getName() : "")
       << " accept=" << (m_acceptWorker ? m_acceptWorker->getName() : "")
       << " recv_timeout=" << m_recvTimeout << "]" << std::endl;
    std::string pfx = prefix.empty() ? "    " : prefix;
    for(auto& i : m_socks) {
        ss << pfx << pfx << *i << std::endl;
    }
    return ss.str();
}

}

//#include "tcp_server.hpp"
//#include "src/config.hpp"
//#include "src/log.hpp"
//namespace stone{
//
//static stone::Logger::ptr g_logger = STONE_LOG_NAME("system");
//
//static stone::ConfigVar<uint64_t>::ptr g_tcp_server_read_timeout = 
//    stone::Config::Lookup("tcp_server.read_timeout",(uint64_t)(60 * 1000 * 2),"tcp server read timeout");
//
//TcpServer::TcpServer(stone::IOManager* worker
//                    ,stone::IOManager* io_worker
//                    ,stone::IOManager* accept_worker)
//    :m_worker(worker)
//    ,m_ioworker(io_worker)
//    ,m_acceptWorker(accept_worker)
//    ,m_recvTimeout(g_tcp_server_read_timeout->getValue())
//    ,m_name("stone/1.0.0")
//    ,m_isStop(true){
//}
//
//TcpServer::~TcpServer(){
//    for(auto& i : m_socks){
//        i->close();
//    }
//    m_socks.clear();
//}
//
//bool TcpServer::bind(Address::ptr addr){
//    std::vector<Address::ptr> addrs;
//    addrs.push_back(addr);
//    std::vector<Address::ptr> fails;
//    return bind(addrs,fails);
//}
//
//bool TcpServer::bind(const std::vector<Address::ptr>& addrs
//                    ,std::vector<Address::ptr>& fails){
//    for(auto& addr : addrs){
//        Socket::ptr sock = Socket::CreateTCP(addr);
//        if(!sock->bind(addr)){
//            STONE_LOG_ERROR(g_logger)<<"bind failed"
//                <<" errno="<<errno<<" errstr="<<strerror(errno)
//                <<" addr["<<addr->toString()<<"]";
//            fails.push_back(addr);
//            continue;
//        }
//        if(!sock->listen()){
//            STONE_LOG_ERROR(g_logger)<<"listen failed"
//                <<" errno="<<errno<<" errstr="<<strerror(errno)
//                <<" addr["<<addr->toString()<<"]";
//            fails.push_back(addr);
//            continue;
//        }
//        m_socks.push_back(sock);
//    }
//
//    if(!fails.empty()){
//        m_socks.clear();
//        return false;
//    }
//
//    for(auto& i : m_socks){
//        STONE_LOG_INFO(g_logger)<<"server bind success: "<<*i;
//    }
//    return true;
//}
//
//bool TcpServer::stop(){
//    m_isStop = true;
//
//    auto self = shared_from_this();
//    m_acceptWorker->schedule([this,self](){
//        for(auto& sock : m_socks){
//            sock->cancelAll();
//            sock->close();
//        }
//        m_socks.clear();
//    });
//    return m_isStop;
//}
//
//bool TcpServer::start(){
//    if(!m_isStop){
//        return true;
//    }
//    m_isStop = false;
//
//    for(auto& sock : m_socks){
//       m_acceptWorker->schedule(std::bind(&TcpServer::startAccept
//                                ,shared_from_this(),sock));
//    }
//    return true;
//}
//
//void TcpServer::handleClient(Socket::ptr client){
//    STONE_LOG_INFO(g_logger)<<"handleClient: "<<*client;
//}
//
//void TcpServer::startAccept(Socket::ptr sock){
//    while(!m_isStop){
//        Socket::ptr client = sock->accept();
//        if(client){
//            client->setRecvTimeout(m_recvTimeout);
//            m_ioworker->schedule(std::bind(&TcpServer::handleClient
//                        ,shared_from_this(),client));
//        }else{
//            STONE_LOG_ERROR(g_logger)<<"accept errno ="<<errno
//                <<" errstr ="<<strerror(errno);
//        }
//    }
//}
//
//
//
//
//}
