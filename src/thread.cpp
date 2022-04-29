#include "thread.hpp"
#include "log.hpp"
#include "util.hpp"
namespace stone{

//当前执行线程指针
static thread_local Thread* t_thread = nullptr;
//当前执行线程名称
static thread_local std::string t_thread_name = "UNKOWN";

static stone::Logger::ptr g_logger = STONE_LOG_NAME("system");

Thread::Thread(std::function<void()> cb,const std::string& name)
    :m_cb(cb)
    ,m_name(name){
    if(name.empty()){
        m_name = "UNKOWN";
    }
    int rt = pthread_create(&m_thread,nullptr,&Thread::run,this);
    if(rt){
        STONE_LOG_ERROR(g_logger)<<"pthread_create thread fail,rt="<<rt
            <<"name="<<name;
        throw std::logic_error("pthread_cerate error");
    }
    m_semaphore.wait();
}
Thread::~Thread(){
    if(m_thread){
        pthread_detach(m_thread);
    }
}

void Thread::join(){
    if(m_thread){
        int rt = pthread_join(m_thread,nullptr);
        if(rt){
            STONE_LOG_ERROR(g_logger)<<"pthread_join thread fail,rt="<<rt
                <<"name="<<m_name;
            throw std::logic_error("pthread_join error");
        }
        m_thread =0;
    }
}

Thread* Thread::GetThis(){
    return t_thread;
}

const std::string& Thread::GetName(){
    return t_thread_name;
}

void Thread::SetName(const std::string& name){
    if(t_thread){
        t_thread->m_name = name;
    }
    t_thread_name = name;
}

void* Thread::run(void* arg){
    Thread* thread = (Thread*)arg;
    t_thread = thread;
    t_thread_name = thread->m_name;
    thread->m_id = stone::GetThreadId();
    pthread_setname_np(pthread_self(),thread->m_name.substr(0,15).c_str());

    std::function<void()> cb;
    cb.swap(thread->m_cb);
    thread->m_semaphore.notify();
    cb();
    return 0;
}




}
