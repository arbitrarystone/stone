#include "src/stone.hpp"

static stone::Logger::ptr g_logger = STONE_LOG_ROOT();

void test_fiber(){
    static  int s_count = 5;
    STONE_LOG_INFO(g_logger)<<"test in fiber s_count="<<s_count;

    sleep(1);
    if(--s_count>=0){
        stone::Scheduler::GetThis()->schedule(&test_fiber,stone::GetThreadId());
    }
}
int main(int argc,char ** argv)
{
    STONE_LOG_INFO(g_logger)<<"main";
    stone::Scheduler sc(3,false,"test");
    sc.start();
    sleep(2);
    STONE_LOG_INFO(g_logger)<<"schedule";
    sc.schedule(&test_fiber);
    sc.stop();
    STONE_LOG_INFO(g_logger)<<"over";
    return 0;
}
