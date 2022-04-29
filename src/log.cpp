#include "log.hpp"
#include <iostream>
#include <stdlib.h>
#include "config.hpp"

namespace stone {

const std::string LogLevel::toStr(LogLevel::Level level)
{
    switch(level)
    {
#define TOSTR(name) \
        case LogLevel::name: \
            return #name;\
            break;
        TOSTR(DEBUG)
        TOSTR(INFO)
        TOSTR(WARNING)
        TOSTR(ERROR)
        TOSTR(FATAL)
        default:
            return "UNKOWN";
#undef TOSTR
    }
}

const LogLevel::Level LogLevel::fromStr(const std::string& str){
#define XX(level,v) \
    if(str == #v){ \
        return LogLevel::level; \
    }
     XX(DEBUG,debug);
    XX(INFO,info);
    XX(WARNING,warning);
    XX(ERROR,error);
    XX(FATAL,fatal);
    XX(DEBUG,DEBUG);
    XX(INFO,INFO);
    XX(WARNING,WARNING);
    XX(ERROR,ERROR);
    XX(FATAL,FATAL);
    return LogLevel::UNKOWN;
#undef XX
}
LogEventWrap::LogEventWrap(LogEvent::ptr e)
    :m_event(e)
{
}
LogEventWrap::~LogEventWrap(){
    m_event->getLogger()->log(m_event,m_event->getLevel());
}
std::stringstream& LogEventWrap::getSS(){
    return m_event->getSS();
}
LogEvent::LogEvent(std::shared_ptr<Logger> logger,LogLevel::Level level,const char* filename, uint32_t line, uint32_t elapse, uint32_t threadId, uint32_t fiberId, uint64_t time,const std::string& thread_name)
    : m_filename(filename)
     ,m_line(line)
     ,m_elapse(elapse)
     ,m_threadId(threadId)
     ,m_fiberId(fiberId)
     ,m_time(time)
     ,m_threadName(thread_name)
     ,m_logger(logger)
     ,m_level(level)
{

}
void LogEvent::format(const char* fmt,...){
    va_list al;
    va_start(al,fmt);
    format(fmt,al);
    va_end(al);
}
void LogEvent::format(const char* fmt,va_list al){
    char* buf = nullptr;
    int len = vasprintf(&buf,fmt,al);
    if(len!=-1){
        m_ss<<std::string(buf,len);
        free(buf);
    }
}
/**
 * @brief 日志内容项格式器
 */
/**
 * @brief 日志时间格式器
 */
class DateFormatterItem:public LogFormatter::FormatterItem{
public:
    DateFormatterItem(const std::string& fmt = "%Y-%m-%d %H:%M:%S")
        :m_format(fmt){
            if(m_format.empty()){
                m_format = "%Y-%m-%d %H:%M:%S";
            }
    }
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
       struct tm tm;
       time_t time = event->getTime();
       localtime_r(&time,&tm);
       char buff[64];
       strftime(buff,sizeof(buff),m_format.c_str(),&tm);
       os<<buff;
    }
private:
    std::string m_format;
};
/**
 * @brief 日志消息格式器
 */
class MessageFormatterItem:public LogFormatter::FormatterItem{
public:
    MessageFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getContent();
    }
};
/**
 * @brief 日志级别格式器
 */
class LevelFormatterItem:public LogFormatter::FormatterItem{
public:
    LevelFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<LogLevel::toStr(level);
    }
};
/**
 * @brief 日志启动时长格式器
 */
class ElapseFormatterItem:public LogFormatter::FormatterItem{
public:
    ElapseFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getElapse();
    }
};
/**
 * @brief 日志名称格式器
 */
class LoggerNameFormatterItem:public LogFormatter::FormatterItem{
public:
    LoggerNameFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getLogger()->getName();
    }
};
/**
 * @brief 日志行号格式器 
 */
class LineFormatterItem:public LogFormatter::FormatterItem{
public:
    LineFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getLine();
    }
};
/**
 * @brief 日志线程号格式器
 */
class ThreadIdFormatterItem:public LogFormatter::FormatterItem{
public:
    ThreadIdFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getThreadId();
    }
};
/**
 * @brief 日志协程号格式器
 */
class FiberIdFormatterItem:public LogFormatter::FormatterItem{
public:
    FiberIdFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getFiberId();
    }
};
class ThreadNameFormatterItem:public LogFormatter::FormatterItem{
public:
    ThreadNameFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getThreadName();
    }
};

/**
 * @brief 日志tab(间隔)格式器
 */
class TabFormatterItem:public LogFormatter::FormatterItem{
public:
    TabFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<"\t";
    }
};
/**
 * @brief 日志文件名格式器
 */
class FileNameFormatterItem:public LogFormatter::FormatterItem{
public:
    FileNameFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<event->getName();
    }
}; 
/**
 * @brief 日志换行格式器
 */
class NewLineFormatterItem:public LogFormatter::FormatterItem{
public:
    NewLineFormatterItem(const std::string& fmt = ""){}
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
        os<<"\n";
    }
};
class StringFormatterItem:public LogFormatter::FormatterItem{
public:
    StringFormatterItem(const std::string& str)
        :m_string(str){

        }
    void format(std::ostream& os,std::shared_ptr<Logger> logger,LogLevel::Level level ,LogEvent::ptr event){
        os<<m_string;
    }
private:
    std::string m_string;
};

/**
 * @brief 日志格式器
 */
LogFormatter::LogFormatter(const std::string& pattern)
        :m_pattern(pattern)    
{
   init(); 
}
std::string LogFormatter::format(std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
    std::stringstream ss;
    for(auto item:m_items){
        item->format(ss,logger,level,event);
    }
    return ss.str();
}
void LogFormatter::init(){
    std::vector<std::tuple<std::string,std::string,int> > vec;
    std::string nstr;
    for(size_t i = 0;i<m_pattern.size();++i){
        if(m_pattern[i]!='%'){
            nstr.append(1,m_pattern[i]);
            continue;
        }
        if((i+1)<m_pattern.size()){
            if(m_pattern[i+1]=='%'){
            nstr.append(1,'%');
            continue;
            }
        }
        size_t n = i+1;
        int fmt_status = 0;
        size_t fmt_begin = 0;
        std::string str;
        std::string fmt;
        while(n<m_pattern.size()){
            if(!fmt_status && (!isalpha(m_pattern[n]) && m_pattern[n]!='{' && m_pattern[n]!= '}')){
                str = m_pattern.substr(i+1,n-i-1);
                break;
            }
            if(fmt_status == 0){
                if(m_pattern[n] == '{') {
                    fmt_status = 1;
                    str = m_pattern.substr(i+1,n-i-1);
                    fmt_begin = n;
                    ++n;
                    continue;
                    }
            }
            else if(fmt_status == 1){
                if(m_pattern[n] == '}'){
                    fmt_status = 0;
                    fmt = m_pattern.substr(fmt_begin+1,n-fmt_begin-1);
                    ++n;
                    break;
                  }
            }
            ++n;
            if(n == m_pattern.size()){
                if(str.empty()){
                    str =m_pattern.substr(i+1);
                }
            }
        }
        if(fmt_status == 0){
            if(!nstr.empty()){
                vec.push_back(std::make_tuple(nstr,"",0));
                nstr.clear();
            }
            vec.push_back(std::make_tuple(str,fmt,1));
            i = n-1;
        } else if(fmt_status ==1 ){
            std::cout<<"pattern parse error: "<<m_pattern<<" - "<<m_pattern.substr(i)<<std::endl;
            vec.push_back(std::make_tuple("<<pattern error>>",fmt,0));
            m_error = true;
        }
    }
    if(!nstr.empty()){
            vec.push_back(std::make_tuple(nstr,"",0));
        }
    static std::map<std::string,std::function<FormatterItem::ptr(const std::string& str)> > s_format_items = {
#define XX(str,C) \
            { #str,[](const std::string& fmt){ return FormatterItem::ptr(new C(fmt)); } }
            XX(d,DateFormatterItem),
            XX(t,ThreadIdFormatterItem),
            XX(F,FiberIdFormatterItem),
            XX(p,LevelFormatterItem),
            XX(c,LoggerNameFormatterItem),
            XX(f,FileNameFormatterItem),
            XX(l,LineFormatterItem),
            XX(m,MessageFormatterItem),
            XX(n,NewLineFormatterItem),
            XX(T,TabFormatterItem),
            XX(r,ElapseFormatterItem),
            XX(N,ThreadNameFormatterItem)

#undef XX
        };
        for(auto& iter:vec ){
            if(std::get<2>(iter)==0){
                m_items.push_back(FormatterItem::ptr(new StringFormatterItem(std::get<0>(iter))));
            }else{
                auto item = s_format_items.find(std::get<0>(iter));
                if(item!=s_format_items.end()){
                    m_items.push_back(item->second(std::get<1>(iter)));
                }else{
                    m_items.push_back(FormatterItem::ptr(new StringFormatterItem("error_format %"+std::get<0>(iter)+">>")));
                    m_error = true;
                }
            }

        }

}

void LogAppender::setFormatter(LogFormatter::ptr val) {
    MutexType::Lock lock(m_mutex);
    m_formatter = val;
    if(m_formatter){
        m_hasFormatter = true;
    }else{
        m_hasFormatter = false;
    }
}

LogFormatter::ptr LogAppender::getFormatter(){
    MutexType::Lock lock(m_mutex);
    return m_formatter; 
}
/**
 * @brief StdoutLogAppender(标准输出器)
 */
void StdoutLogAppender::log(std::shared_ptr<Logger> logger,LogLevel::Level level, LogEvent::ptr event){
    if(level>=m_level)
    {
        MutexType::Lock lock(m_mutex);
        std::cout<<m_formatter->format(logger,level,event);
    }
}

std::string StdoutLogAppender::toYamlString(){
    MutexType::Lock lock(m_mutex);
    YAML::Node node;
    node["type"] = "StdoutLogAppender";
    if(m_level!=LogLevel::UNKOWN){
        node["level"] = LogLevel::toStr(m_level);
    }
    if(m_hasFormatter && m_formatter){
        node["formatter"] = m_formatter->getPattern();
    }
    std::stringstream ss;
    ss<<node;
    return ss.str();
}
/**
 * @brief FileLogAppender(文件输出器)
 */
FileLogAppender::FileLogAppender(const std::string& fileName):m_filename(fileName){
   if(!reopen())
   {
       std::cout<<"error"<<std::endl;
   }
}
std::string FileLogAppender::toYamlString(){
    MutexType::Lock lock(m_mutex);
    YAML::Node node;
    node["type"] = "FileLogAppender";
    node["file"] = m_filename;
    if(m_level!=LogLevel::UNKOWN){
        node["level"] = LogLevel::toStr(m_level);
    }
    if(m_hasFormatter && m_formatter){
        node["formatter"] = m_formatter->getPattern();
    }
    std::stringstream ss;
    ss<<node;
    return ss.str();
}
bool FileLogAppender::reopen(){
    MutexType::Lock lock(m_mutex);
    if(m_filestream){
        m_filestream.close();
    }
    m_filestream.open(m_filename);
    if(m_filestream){
        return true;
    }
    return false;
}
void FileLogAppender::log(std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event){
    if(level>=m_level)
    {
        MutexType::Lock lock(m_mutex);
        m_filestream<<m_formatter->format(logger,level,event);
    }
}

/**
 * @brief  Logger(日志器)
 */
Logger::Logger(const std::string& name)
    :m_name(name)
    ,m_level(LogLevel::DEBUG){
    m_formatter.reset(new stone::LogFormatter("%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"));
    }
void Logger::setFormatter(LogFormatter::ptr val){
    MutexType::Lock lock(m_mutex);
    m_formatter = val;
    for(auto& i:m_appenders){
        MutexType::Lock ll(i->m_mutex);
        if(!i->m_hasFormatter){
            i->m_formatter = m_formatter;
        }
    }
}
std::string Logger::toYamlString(){
    MutexType::Lock lock(m_mutex);
    YAML::Node node;
    node["name"] = m_name;
    if(m_level!=LogLevel::UNKOWN){
         node["level"] = LogLevel::toStr(m_level);
    }
    if(m_formatter){
        node["formatter"] =m_formatter->getPattern();
    }
    for(auto& i:m_appenders){
        node["appenders"].push_back(YAML::Load(i->toYamlString()));
    }
    std::stringstream ss;
    ss<<node;
    return ss.str();
}
void Logger::setFormatter(const std::string& val){
    stone::LogFormatter::ptr new_val(new stone::LogFormatter(val));
    if(new_val->isError()){
        std::cout<<"Logger setFormatter name = "<<m_name
                 <<"value = "<<val<<" invalid formatter"
                 <<std::endl;
        return;
    }
    setFormatter(new_val);
}
LogFormatter::ptr Logger::getFormatter(){
    MutexType::Lock lock(m_mutex);
    return m_formatter;
}
void Logger::addAppender(LogAppender::ptr appender){
    MutexType::Lock lock(m_mutex);
    if(!appender->getFormatter()){
        MutexType::Lock ll(appender->m_mutex);
        appender->m_formatter = m_formatter;
    }
    m_appenders.push_back(appender);
}
void Logger::delAppender(LogAppender::ptr appender){
    MutexType::Lock lock(m_mutex);
    for(auto iter = m_appenders.begin();
             iter!=m_appenders.end();
             ++iter){
        if(*iter == appender){
            m_appenders.erase(iter);
            break;
        }
    }
}
void Logger::clearAppender(){
    MutexType::Lock lock(m_mutex);
    m_appenders.clear();
}
void Logger::log(LogEvent::ptr event,LogLevel::Level level){
    if(m_level<=level){
        auto self = shared_from_this();
        MutexType::Lock lock(m_mutex);
        if(!m_appenders.empty()){
             for(auto appender:m_appenders){
                appender->log(self,level,event);
             }
        }else if(m_root){
            m_root->log(event,level);
        }
    }
}

void Logger::debug(LogEvent::ptr event){
    log(event,LogLevel::Level::DEBUG);
}
void Logger::info(LogEvent::ptr event){
    log(event,LogLevel::Level::INFO);
}
void Logger::warning(LogEvent::ptr event){
    log(event,LogLevel::Level::WARNING);
}
void Logger::error(LogEvent::ptr event){
    log(event,LogLevel::Level::ERROR);
}
void Logger::fatal(LogEvent::ptr event){
    log(event,LogLevel::Level::FATAL);
}
LoggerManager::LoggerManager(){
    m_root.reset(new Logger);
    m_root->addAppender(LogAppender::ptr(new StdoutLogAppender));
    m_loggers[m_root->m_name] = m_root;
    init();
}
Logger::ptr LoggerManager::getLogger(const std::string& name){
    MutexType::Lock lock(m_mutex);
    auto iter = m_loggers.find(name);
    if(iter!=m_loggers.end()){
        return iter->second;
    }
    Logger::ptr logger(new Logger(name));
    logger->m_root = m_root;
    m_loggers[name] = logger;
    return logger;
}
struct LogAppenderDefine{
    int type;
    LogLevel::Level level = LogLevel::Level::UNKOWN;
    std::string formatter;
    std::string file;
    bool operator==(const LogAppenderDefine& oth) const{
        return type == oth.type
               && level == oth.level
               && formatter == oth.formatter
               && file == oth.file;
    }
};
struct LogDefine{
    std::string name;
    LogLevel::Level level = LogLevel::Level::UNKOWN;
    std::string formatter;
    std::vector<LogAppenderDefine> appenders;
    bool operator==(const LogDefine& oth) const {
        return name == oth.name
            && level == oth.level
            && formatter == oth.formatter
            && appenders == oth.appenders;
    }
    bool operator<(const LogDefine& oth) const {
        return name < oth.name;
    }
};

template<>
class LexicalCast<std::string,std::set<LogDefine> > {
public:
        std::set<LogDefine> operator()(const std::string& v){
        YAML::Node node =YAML::Load(v);
        std::set<LogDefine> vec;
        std::stringstream ss;
        for(size_t i = 0;i<node.size();++i){
            auto n = node[i];
            if(!n["name"].IsDefined()){
                std::cout<<"log config error: name is null"<< n
                         << std::endl;
                continue;
            }
            LogDefine ld;
            ld.name = n["name"].as<std::string>();
            ld.level = LogLevel::fromStr(n["level"].IsScalar() ? n["level"].as<std::string>() : "");
            if(n["formatter"].IsDefined()){
                ld.formatter = n["formatter"].as<std::string>();
            }
            if(n["appenders"].IsDefined()){
                for(size_t x =0;x<n["appenders"].size();++x){
                    auto a = n["appenders"][x];
                    if(!a["type"].IsDefined()){
                        std::cout<<"log config error: appender type is null"<< a
                                 << std::endl;
                        continue;
                    }
                    std::string type = a["type"].as<std::string>();
                    LogAppenderDefine lad;
                    if(type == "FileLogAppender") {
                        lad.type =1;
                        if(!a["file"].IsDefined()){
                            std::cout<<"log config error: fileappender file is null"<< a
                                     << std::endl;
                             continue;
                        }
                        lad.file = a["file"].as<std::string>();
                        if(a["formatter"].IsDefined()){
                            lad.formatter = a["formatter"].as<std::string>();
                        }
                    }else if(type == "StdoutLogAppender"){
                        lad.type =2;
                    }else {
                        std::cout<<"log config error: appender type is invalid"<< a
                                 << std::endl;
                        continue;
                    }

                    ld.appenders.push_back(lad);
                }
            }
            vec.insert(ld);
        }
        return vec;
    }
};

template<>
class LexicalCast<std::set<LogDefine>,std::string>{
public:
    std::string operator()(const std::set<LogDefine> v){
        YAML::Node node;
        for(auto& i:v){
            YAML::Node n;
            n["name"] = i.name;
            if(i.level!=LogLevel::UNKOWN){
                n["level"] = LogLevel::toStr(i.level);
            }
            if(!i.formatter.empty()){
                n["formatter"] = i.formatter;
            }
            for(auto& a:i.appenders){
                YAML::Node na;
                if(a.type ==1){
                    na["type"] = "FileLogApender";
                    na["file"] = a.file;
                }else if(a.type == 2){
                    na["type"] = "StdoutLogAppender";
                }
                if(a.level!=LogLevel::UNKOWN){
                    na["level"] = LogLevel::toStr(a.level);
                }
                if(!a.formatter.empty()){
                    na["formatter"] = a.formatter;
                }
                n["appenders"].push_back(na);
            }
            node.push_back(n);
        }
        std::stringstream ss;
        ss<<node;
        return ss.str();
    }
};


stone::ConfigVar<std::set<LogDefine> >::ptr g_log_defines = 
    stone::Config::Lookup("logs",std::set<LogDefine>(),"logs config");
    
struct LogIniter {
    LogIniter(){
        g_log_defines->addListener([](const std::set<LogDefine>& old_value,
                    const std::set<LogDefine>& new_value){
                STONE_LOG_INFO(STONE_LOG_ROOT())<<"on_log_conf_change";
                for(auto& i:new_value){
                    auto iter = old_value.find(i);
                    stone::Logger::ptr logger;
                    if(iter==old_value.end()){
                        logger = STONE_LOG_NAME(i.name);
                    }else {
                        if(!(i==*iter)){
                              logger = STONE_LOG_NAME(i.name);
                            }
                        }   
                    logger->setLevel(i.level);
                    if(!i.formatter.empty()){
                    logger->setFormatter(i.formatter);
                    }
                    logger->clearAppender();
                    for(auto& a:i.appenders){
                        stone::LogAppender::ptr ap;
                        if(a.type == 1){
                            ap.reset(new FileLogAppender(a.file));
                        }else if(a.type == 2){
                            ap.reset(new StdoutLogAppender);
                        }
                        ap->setLevel(i.level);
                        if(!a.formatter.empty()){
                            LogFormatter::ptr fmt(new LogFormatter(a.formatter));
                            if(!fmt->isError()){
                                ap->setFormatter(fmt);
                            }else{
                                std::cout<<"logger.name ="<<i.name
                                         <<"  a.type="<<a.type<<" formatter="<<a.formatter<<"is invalid"<<std::endl;
                            }
                        }
                        logger->addAppender(ap);
                    }
                }
                for(auto& i:old_value){
                    auto iter = new_value.find(i);
                    if(iter == new_value.end()){
                        auto logger = STONE_LOG_NAME(i.name);
                        logger->setLevel((LogLevel::Level)100);
                        logger->clearAppender();
                    }
                }
        });
    }
};

static LogIniter __log_init;
void LoggerManager::init(){

}
std::string LoggerManager::toYamlString(){
    MutexType::Lock lock(m_mutex);
    YAML::Node node;
    for(auto& i: m_loggers){
        node.push_back(i.second->toYamlString());
    }
    std::stringstream ss;
    ss<<node;
    return ss.str();
}
};
