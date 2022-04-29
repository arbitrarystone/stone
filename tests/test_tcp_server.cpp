#include "src/tcp_server.hpp"
#include "src/iomanager.hpp"
#include "src/log.hpp"

static stone::Logger::ptr g_logger = STONE_LOG_ROOT();
void run(){
    auto addr = stone::Address::LookupAny("0.0.0.0:8020");

    //auto addr2 = stone::UnixAddress::ptr(new stone::UnixAddress("/tmp/unix_addr"));
    STONE_LOG_INFO(g_logger)<<*addr;//<<" - "<<//*addr2;

    std::vector<stone::Address::ptr> addrs;
    addrs.push_back(addr);
    //addrs.push_back(addr2);

    stone::TcpServer::ptr tcp_server(new stone::TcpServer);
    std::vector<stone::Address::ptr> fails;
    while(!tcp_server->bind(addrs,fails)){
        sleep(2);
    }
    tcp_server->start();

}

int main(int argc,char** argv){
    stone::IOManager iom(2);
    iom.schedule(run);
    return 0;
}
