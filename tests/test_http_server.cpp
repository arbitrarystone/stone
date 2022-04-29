#include "src/http/http_server.hpp"
#include "src/log.hpp"

static stone::Logger::ptr g_logger = STONE_LOG_ROOT();
void run(){
    stone::http::HttpServer::ptr server(new stone::http::HttpServer);
    auto addr = stone::Address::LookupAnyIPAddress("0.0.0.0:8020");
    while(!server->bind(addr)){
        sleep(2);
    }
    server->start();
}
int main(int argc,char** argv){
    stone::IOManager iom(2);
    iom.schedule(run);
    return 0;
}
