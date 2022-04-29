#include "src/log.hpp"
#include "src/stone.hpp"
stone::Logger::ptr g_logger = STONE_LOG_ROOT();

void run_in_fiber(){
    STONE_LOG_INFO(g_logger)<<"run_in_fiber begin";
    stone::Fiber::YieldToHold();
    STONE_LOG_INFO(g_logger)<<"run_in_fiber end";
    stone::Fiber::YieldToHold();
}

void test_fiber(){
    STONE_LOG_INFO(g_logger)<<"main begin -1";
    {
        stone::Fiber::GetThis();
        STONE_LOG_INFO(g_logger)<<"main begin";
        stone::Fiber::ptr fiber(new stone::Fiber(&run_in_fiber));
        fiber->call();
        STONE_LOG_INFO(g_logger)<<"main after swapin";
        fiber->call();
        STONE_LOG_INFO(g_logger)<<"main after end";
        fiber->call();
    }
    STONE_LOG_INFO(g_logger)<<"main after end 2";
}

int main(int argc,char** argv){
    stone::Thread::SetName("main");
    std::vector<stone::Thread::ptr> thrs;
    for(size_t i=0;i<3;++i){
        thrs.push_back(stone::Thread::ptr(
                    new stone::Thread(&test_fiber,"name_"+std::to_string(i))));
    }
    for(auto i : thrs)
    {
        i->join();
    }
    return 0;
}
