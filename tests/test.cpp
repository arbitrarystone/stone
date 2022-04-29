#include <iostream>
#include "src/log.hpp"
#include "src/util.hpp"
int main(int argc,char** argv)
{
    stone::Logger::ptr logger(new stone::Logger);
    logger->addAppender(stone::LogAppender::ptr(new stone::StdoutLogAppender));

    stone::FileLogAppender::ptr file_appender(new stone::FileLogAppender("./log.txt"));
    stone::LogFormatter::ptr fmt(new stone::LogFormatter("%d%T%p%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(stone::LogLevel::ERROR);

    logger->addAppender(file_appender);
    //stone::LogEvent::ptr event(new stone::LogEvent(logger,stone::LogLevel::DEBUG,__FILE__,__LINE__,0,stone::GetThreadId(),stone::GetFiberId(),time(0)));
    //event->getSS()<<"Hello log";
    // logger->log(event,stone::LogLevel::DEBUG);
    STONE_LOG_INFO(logger)<<"hello stone log";
    STONE_LOG_ERROR(logger)<<"hello stone log";

    STONE_LOG_FMT_WARNING(logger,"test macro fmt error %s","aa");
    auto l = stone::LoggerMgr::GetInstance()->getLogger("xxx");
    STONE_LOG_INFO(l)<<"xxx";
    
    return 0;
}
