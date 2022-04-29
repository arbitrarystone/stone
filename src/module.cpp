#include "module.hpp"
#include "config.hpp"
#include "env.hpp"
#include "library.hpp"
#include "util.hpp"
#include "log.hpp"
#include "application.hpp"
namespace stone{

static stone::ConfigVar<std::string>::ptr g_module_path = 
    stone::Config::Lookup("module.path",std::string("module"),"module path");

static stone::Logger::ptr g_logger = 
    STONE_LOG_ROOT();
Module::Module(const std::string& name
      ,const std::string& version
      ,const std::string& filename
      ,uint32_t type)
    :m_name(name)
    ,m_version(version)
    ,m_filename(filename)
    ,m_id(name + "/" + version)
    ,m_type(type){
}

void Module::onBeforeArgsParse(int argc,char** argv){
}

void Module::onAfterArgsParse(int argc,char** argv){
}

bool Module::onLoad(){
    STONE_LOG_INFO(g_logger) << "onLoad";
    return true;
}

bool Module::onUnload(){
    STONE_LOG_INFO(g_logger) << "onUnload";
    return true;
}

bool Module::onConnect(stone::Stream::ptr stream){
    STONE_LOG_INFO(g_logger) << "onConnect";
    return true;
}

bool Module::onDisconnect(stone::Stream::ptr stream){
    STONE_LOG_INFO(g_logger) << "onDisconnect";
    return true;

}

bool Module::onServerReady(){
    STONE_LOG_INFO(g_logger) << "onServerReady";
    return true;
}

bool Module::onServerUp(){
    STONE_LOG_INFO(g_logger) << "onServerUp";
    return true;
}

std::string Module::statusString(){
    std::stringstream ss;
    ss << "Module name=" << getName()
       << " version=" << getVersion()
       << " filename=" << getFileName()
       << std::endl;
    return ss.str();
}

ModuleManager::ModuleManager(){
}

Module::ptr ModuleManager::get(const std::string& name){
    RWMutexType::ReadLock lock(m_mutex);
    auto it = m_modules.find(name);
    return it == m_modules.end() ? nullptr : it->second;
}

void ModuleManager::add(Module::ptr m){
    del(m->getId());
    RWMutexType::WriteLock lock(m_mutex);
    m_modules[m->getId()] = m;
    m_type2Modules[m->getType()][m->getId()] = m;
}

void ModuleManager::del(const std::string& name){
    Module::ptr module;
    RWMutexType::WriteLock lock(m_mutex);
    auto it = m_modules.find(name);
    if(it == m_modules.end()){
        return;
    }
    module = it->second;
    m_modules.erase(it);
    m_type2Modules[module->getType()].erase(module->getId());
    if(m_type2Modules[module->getType()].empty()){
        m_type2Modules.erase(module->getType());
    }
    lock.unlock();
    module->onUnload();
}

void ModuleManager::delAll(){
    RWMutexType::ReadLock lock(m_mutex);
    auto tmp = m_modules;
    lock.unlock();
    for(auto& i: tmp){
        del(i.first);
    }
}

void ModuleManager::init(){
    auto path = EnvMgr::GetInstance()->getAbsolutePath(g_module_path->getValue());

    std::vector<std::string> files;
    stone::FSUtil::ListAllFile(files,path,"so");

    std::sort(files.begin(),files.end());
    for(auto& i : files){
        initModule(i);
    }

}

void ModuleManager::onConnect(stone::Stream::ptr stream){ 
    std::vector<Module::ptr> ms;
    listAll(ms);

    for(auto& i : ms){
        i->onConnect(stream);
    }
}

void ModuleManager::onDisconnect(stone::Stream::ptr stream){
    std::vector<Module::ptr> ms;
    listAll(ms);

    for(auto& i : ms){
        i->onDisconnect(stream);
    }
}

void ModuleManager::listAll(std::vector<Module::ptr>& ms){
    RWMutexType::ReadLock lock(m_mutex);
    for(auto& i : m_modules){
        ms.push_back(i.second);
    }
}

void ModuleManager::listByType(uint32_t type,std::vector<Module::ptr>& ms){
    RWMutexType::ReadLock lock(m_mutex);
    auto it = m_type2Modules.find(type);
    if(it == m_type2Modules.end()){
        return;
    }
    for(auto& i : it->second){
        ms.push_back(i.second);
    }
}

void ModuleManager::foreach(uint32_t type,std::function<void(Module::ptr)> cb){
    std::vector<Module::ptr> ms;
    listByType(type,ms);
    for(auto& i : ms){
        cb(i);
    }
}

void ModuleManager::initModule(const std::string& path){
    Module::ptr m = Library::GetModule(path);
    if(m){
        add(m);
    }
}


}
