#include "src/stone.hpp"
stone::Logger::ptr g_logger = STONE_LOG_ROOT();
int count = 0;
void fun1(){
    STONE_LOG_INFO(g_logger)<<"name ="<<stone::Thread::GetName()
                            <<"this.name = "<<stone::Thread::GetThis()->getName()
                            <<"id :"<<stone::GetThreadId()
                            <<"this.id"<<stone::Thread::GetThis()->getId();
}

void fun2(){

}

int main(int argc,char** argv){
    std::vector<stone::Thread::ptr> thrs;
    for(int i=0;i<5;++i){
        stone::Thread::ptr thr(new stone::Thread(&fun1,"name_"+std::to_string(i)));
        thrs.push_back(thr);
    }
    for(int i=0;i<5;++i){
        thrs[i]->join();
    }
    STONE_LOG_INFO(g_logger)<<"thread test end";
    return 0;
}
