#include "src/socket.hpp"
#include "src/stone.hpp"
#include "src/iomanager.hpp"
#include "src/address.hpp"
static stone::Logger::ptr g_logger = STONE_LOG_ROOT();

void test_socket(){
    stone::IPAddress::ptr addr = stone::Address::LookupAnyIPAddress("www.baidu.com");
    if(addr){
        STONE_LOG_INFO(g_logger)<<"get address:"<<addr->toString();
    } else {
        STONE_LOG_ERROR(g_logger)<<"get address fail";
        return;
    }
    stone::Socket::ptr sock = stone::Socket::CreateTCP(addr);
    addr->setPort(80);
    STONE_LOG_INFO(g_logger)<<addr->toString();
    if(!sock->connect(addr)){
        STONE_LOG_ERROR(g_logger)<<"connect "<< addr->toString()<<" fail";
    } else {
        STONE_LOG_INFO(g_logger)<<"connect "<< addr->toString()<<" connected";
    }

    const char buff[] = "GET / HTTP/1.0\r\n\r\n";
    int rt = sock->send(buff,sizeof(buff));
    if(rt <=0){
        STONE_LOG_INFO(g_logger)<<"send fail rt ="<<rt;
        return;
    }
    std::string buffs;
    buffs.resize(4096);
    rt = sock->recv(&buffs[0],buffs.size());

    if(rt <= 0){
        STONE_LOG_INFO(g_logger)<<"recv fail rt ="<<rt;
    }
    buffs.resize(rt);
    STONE_LOG_INFO(g_logger)<< buffs;
}
int main(int argc,char** argv){
    stone::IOManager iom;
    iom.schedule(&test_socket);
    return 0;
}
