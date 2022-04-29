#ifndef __STONE_MOUDLE_HPP__
#define __STONE_MOUDLE_HPP__
#include <memory>
#include <string>
#include <map>
#include <unordered_map>
#include <functional>
#include "stream.hpp"
#include "singleton.hpp"
#include "mutex.hpp"

namespace stone{
class Module{
public:
    enum Type{
        MOUDLE = 0,
        ROCK = 1
    };
    typedef std::shared_ptr<Module> ptr;
    Module(const std::string& name
          ,const std::string& version
          ,const std::string& filename
          ,uint32_t type = MOUDLE);
    virtual ~Module() {}

    virtual void onBeforeArgsParse(int argc,char** argv);
    virtual void onAfterArgsParse(int argc,char** argv);

    virtual bool onLoad();
    virtual bool onUnload();

    virtual bool onConnect(stone::Stream::ptr stream);
    virtual bool onDisconnect(stone::Stream::ptr stream);

    virtual bool onServerReady();
    virtual bool onServerUp();

    virtual std::string statusString();

    const std::string& getName() const { return m_name; }
    const std::string& getVersion() const { return m_version; }
    const std::string& getFileName() const { return m_filename; }
    const std::string& getId() const { return m_id; }
    uint32_t getType() const { return m_type; }

    void setFileName(const std::string& v) { m_filename = v; }
protected:
    std::string m_name;
    std::string m_version;
    std::string m_filename;
    std::string m_id;
    uint32_t m_type;
};

class ModuleManager{
public:
    typedef RWMutex RWMutexType;
    
    ModuleManager();

    void add(Module::ptr m);
    void del(const std::string& name);
    void delAll();

    void init();
    Module::ptr get(const std::string& name);

    void onConnect(stone::Stream::ptr stream);
    void onDisconnect(stone::Stream::ptr stream);
    void listAll(std::vector<Module::ptr>& ms);
    void listByType(uint32_t type,std::vector<Module::ptr>& ms);
    void foreach(uint32_t type,std::function<void(Module::ptr)> cb);
private:
    void initModule(const std::string& path);
private:
    RWMutexType m_mutex;
    std::unordered_map<std::string,Module::ptr> m_modules;
    std::unordered_map<uint32_t,
            std::unordered_map<std::string,Module::ptr> > m_type2Modules;
};
typedef stone::Singleton<ModuleManager> ModuleMgr;
}
#endif
