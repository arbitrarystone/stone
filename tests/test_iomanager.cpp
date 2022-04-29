#include "src/stone.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include "src/iomanager.hpp"
stone::Logger::ptr g_logger = STONE_LOG_ROOT();
void test_fiber(){
    STONE_LOG_INFO(g_logger)<<"test_fiber";
    int sock = socket(AF_INET,SOCK_STREAM,0);
    fcntl(sock,F_SETFL,O_NONBLOCK);

    sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    inet_pton(AF_INET,"110.242.68.4",&addr.sin_addr.s_addr);

   connect(sock,(const sockaddr*)&addr,sizeof(addr));
   stone::IOManager::GetThis()->addEvent(sock,stone::IOManager::READ,[](){
           STONE_LOG_INFO(g_logger)<<"read callback";
            });
   stone::IOManager::GetThis()->addEvent(sock,stone::IOManager::WRITE,[=](){
           STONE_LOG_INFO(g_logger)<<"write callback";
            stone::IOManager::GetThis()->cancelEvent(sock,stone::IOManager::READ);
            close(sock);
           });
}
void test1(){
    stone::IOManager iom(2,false);
    iom.schedule(&test_fiber);

}
stone::Timer::ptr s_timer;
void test_timer(){
    stone::IOManager iom(2);
    s_timer = iom.addTimer(500,[](){
        STONE_LOG_INFO(g_logger)<<"hello timer"; 
        static int i=0;
        if(++i == 5){
            s_timer->reset(1000,true);
        }
    },true);
}
int main(int argc,char** argv){
    test_timer();
    return 0;
}
