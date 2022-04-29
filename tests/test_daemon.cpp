#include "src/daemon.hpp"
#include "src/iomanager.hpp"
#include "src/log.hpp"
static stone::Logger::ptr g_logger = STONE_LOG_ROOT();

int server_main(int argc,char** argv){
    stone::IOManager iom(1);
    iom.addTimer(1000,[](){
            STONE_LOG_INFO(g_logger)<<"onTimer";
    },true);
    return 0;
}
int main(int argc,char** argv){
    return stone::start_daemon(argc,argv,server_main,argc!=1);
}
