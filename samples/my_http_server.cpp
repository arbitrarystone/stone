#include "src/http/http_server.hpp"
#include "src/log.hpp"
static stone::Logger::ptr g_logger = STONE_LOG_ROOT();

void run(){
    g_logger->setLevel(stone::LogLevel::INFO);
    stone::Address::ptr addr = stone::Address::LookupAnyIPAddress("0.0.0.0:8020");
    if(!addr){
        STONE_LOG_ERROR(g_logger)<<"get address error";
        return;
    }
    stone::http::HttpServer::ptr http_server(new stone::http::HttpServer);
    while(!http_server->bind(addr)){
        STONE_LOG_ERROR(g_logger)<<"bind "<<*addr<<" error";
        sleep(1);
    }
    http_server->start();
}
int main(){
    stone::IOManager iom(1);
    iom.schedule(run);
    return 0;
}
