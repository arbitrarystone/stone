#ifndef __STONE_APPLICATION_H__
#define __STONE_APPLICATION_H__

#include "src/http/http_server.hpp"
#include <string>
#include <vector>
#include <map>
//#include "src/streams/service_discovery.h"
//#include "src/rock/rock_stream.h"

namespace stone {

class Application {
public:
    Application();

    static Application* GetInstance() { return s_instance;}
    bool init(int argc, char** argv);
    bool run();

    bool getServer(const std::string& type, std::vector<TcpServer::ptr>& svrs);
    void listAllServer(std::map<std::string, std::vector<TcpServer::ptr> >& servers);

    //ZKServiceDiscovery::ptr getServiceDiscovery() const { return m_serviceDiscovery;}
    //RockSDLoadBalance::ptr getRockSDLoadBalance() const { return m_rockSDLoadBalance;}
private:
    int main(int argc, char** argv);
    int run_fiber();
private:
    int m_argc = 0;
    char** m_argv = nullptr;

    //std::vector<stone::http::HttpServer::ptr> m_httpservers;
    std::map<std::string, std::vector<TcpServer::ptr> > m_servers;
    IOManager::ptr m_mainIOManager;
    static Application* s_instance;

    //ZKServiceDiscovery::ptr m_serviceDiscovery;
    //RockSDLoadBalance::ptr m_rockSDLoadBalance;
};

}

#endif

//#ifndef __STONE_APPLICATION_HPP__
//#define __STONE_APPLICATION_HPP__
//#include <string>
//#include <vector>
//#include <map>
//#include "iomanager.hpp"
//#include "tcp_server.hpp"
//#include "http/http_server.hpp"
//namespace stone{
//class Application{
//public:
//    Application();
//    static Application* GetInstance() { return s_instance; }
//    bool run();
//    bool init(int argc,char** argv);
//    
//    bool getServers(const std::string& type,std::vector<TcpServer::ptr>& servers);
//    void listAllServers(std::map<std::string,std::vector<TcpServer::ptr> >& servers);
//private:
//    int main(int argc,char** argv);
//    int run_fiber();
//private:
//    int m_argc = 0;
//    char** m_argv = nullptr;
//    std::vector<stone::TcpServer::ptr> m_servers;
//    //std::map<std::string,std::vector<TcpServer::ptr> > m_servers;
//    IOManager::ptr m_mainIOManager;
//    static Application* s_instance;
//};
//}
//#endif
