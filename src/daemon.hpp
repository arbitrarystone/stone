#ifndef __STONE_DAEMON_HPP__
#define __STONE_DAEMON_HPP__
#include <functional>
#include <unistd.h>
#include "src/singleton.hpp"
namespace stone{

struct ProcessInfo{
    pid_t parent_id = 0;
    pid_t main_id = 0;
    uint64_t parent_start_time = 0;
    uint64_t main_start_time = 0;
    uint32_t restart_count = 0;
    std::string toString() const;
};

typedef stone::Singleton<ProcessInfo> ProcessInfoMgr;
int start_daemon(int argc,char** argv
            ,std::function<int(int argc,char** argv)> main_cb
            ,bool is_daemon);
}
#endif
