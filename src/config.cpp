#include "config.hpp"
#include "env.hpp"
#include "util.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

namespace stone{

static stone::Logger::ptr g_logger = STONE_LOG_NAME("system");

ConfigVarBase::ptr Config::LookupBase(const std::string& name){
    auto iter =GetDatas().find(name);
    RWMutexType::ReadLock lock(GetMutex());
    return iter==GetDatas().end()?nullptr:iter->second;
}
void Config::ListAllMember(const std::string& prefix,
                          const YAML::Node& node,
                          std::list<std::pair<std::string,const YAML::Node> >& output){
            if(prefix.find_first_not_of("abcdefghijklmnopqrstuvwxyz._0123456789")
                        !=std::string::npos){
                    STONE_LOG_ERROR(STONE_LOG_ROOT())<<"COnfig invalid name: "<<prefix<<" : "<<node;
                    return;
            }
            output.push_back(std::make_pair(prefix,node));
            if(node.IsMap()){
                for(auto iter = node.begin();
                         iter!=node.end();
                         ++iter){
                    ListAllMember(prefix.empty()?iter->first.Scalar():prefix+'.'+iter->first.Scalar(),iter->second,output);
                }
            }

}
void Config::Visit(std::function<void(ConfigVarBase::ptr)> cb){
    RWMutexType::ReadLock lock(GetMutex());
    ConfigVarMap& m = GetDatas();
    for(auto it = m.begin();
             it !=m.end();
             ++it){
        cb(it->second);
    }
}

static std::map<std::string, uint64_t> s_file2modifytime;
static stone::Mutex s_mutex;

void Config::LoadFromConfDir(const std::string& path, bool force) {
    std::string absoulte_path = stone::EnvMgr::GetInstance()->getAbsolutePath(path);
    std::vector<std::string> files;
    FSUtil::ListAllFile(files, absoulte_path, ".yml");

    for(auto& i : files) {
        {
            struct stat st;
            lstat(i.c_str(), &st);
            stone::Mutex::Lock lock(s_mutex);
            if(!force && s_file2modifytime[i] == (uint64_t)st.st_mtime) {
                continue;
            }
            s_file2modifytime[i] = st.st_mtime;
        }
        try {
            YAML::Node root = YAML::LoadFile(i);
            LoadFromYaml(root);
            STONE_LOG_INFO(g_logger) << "LoadConfFile file="
                << i << " ok";
        } catch (...) {
            STONE_LOG_ERROR(g_logger) << "LoadConfFile file="
                << i << " failed";
        }
    }
}

void Config::LoadFromYaml(const YAML::Node& root){
    std::list<std::pair<std::string,const YAML::Node> > all_nodes;
    ListAllMember("",root,all_nodes);

    for(auto& i:all_nodes){
        std::string key = i.first;
        if(key.empty()){
            continue; 
        }
        std::transform(key.begin(),key.end(),key.begin(),::tolower);
        ConfigVarBase::ptr var = LookupBase(key); 
        if(var){
            if(i.second.IsScalar()){
                var->fromString(i.second.Scalar());
            }else{
                std::stringstream ss;
                ss<<i.second;
                var->fromString(ss.str());
            }
        }
    }
}
}
