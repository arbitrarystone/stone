#ifndef __STONE_THREAD_HPP__
#define __STONE_THREAD_HPP__

#include "mutex.hpp"
#include <functional>
namespace stone{

class Thread{
public:
    typedef std::shared_ptr<Thread> ptr;
public:

    Thread(std::function<void()> cb,const std::string& name);
    
    ~Thread();

    pid_t getId() const { return m_id; }
    
    const std::string getName() const { return m_name; }

    void join();
    
    //获取当前执行的线程指针
    static Thread* GetThis();
    //获取当前执行的线程名称
    static const std::string& GetName();
    //设置当前执行线程名称
    static void SetName(const std::string& name);
private:
    //线程执行函数
    static void* run(void* arg);
    Thread(const Thread&) = delete;
    Thread(const Thread&&) = delete;
    Thread& operator=(const Thread&) = delete;
private:
    pid_t m_id = -1;
    pthread_t m_thread = 0;
    std::function<void()> m_cb;
    std::string m_name;
    Semaphore m_semaphore;
};
}
#endif
