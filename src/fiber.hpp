#ifndef __STONE_FIBER_HPP__
#define __STONE_FIBER_HPP__
#include <memory>
#include <functional>
#include <ucontext.h>
class Scheduler;
namespace stone{

class Fiber:public std::enable_shared_from_this<Fiber>{

friend class Scheduler;

public:
    typedef std::shared_ptr<Fiber> ptr;
public:
    enum State{
        INIT,
        HOLD,
        EXEC,
        TERM,
        READY,
        EXCEPT
    };
private:
    Fiber();
public:
    Fiber(std::function<void()> cb,size_t stacksize=0,bool use_caller = false);

    ~Fiber();

    void reset(std::function<void()> cb);

    void swapIn();

    void swapOut();

    void call();

    void back();

    uint64_t getId() const { return m_id; }

    State getState() const { return m_state; }

public:
   static void SetThis(Fiber* f);

   static Fiber::ptr GetThis();

   static void YieldToReady();

   static void YieldToHold();

   static uint64_t TotalFibers();

   static void MainFunc();

   static void CallerMainFunc();

   static uint64_t GetFiberId();

private:
    uint64_t m_id = 0;
    uint32_t m_stacksize = 0;
    State m_state = INIT;
    ucontext_t m_ctx;
    void* m_stack = nullptr;
    std::function<void()> m_cb;
};
}
#endif
