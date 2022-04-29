#include "../src/config.hpp"
#include "../src/log.hpp"
#include <yaml-cpp/yaml.h>
#include <iostream>
stone::ConfigVar<int>::ptr g_int_value_config =
    stone::Config::Lookup("system.port",(int)8080,"system port");
stone::ConfigVar<float>::ptr g_intx_value_config =
    stone::Config::Lookup("system.port",(float)8080,"system port");
stone::ConfigVar<float>::ptr g_float_value_config =
    stone::Config::Lookup("system.value",(float)10.2f,"system value");
stone::ConfigVar<std::vector<int> >::ptr g_int_vec_value_config =
    stone::Config::Lookup("system.int_vec",std::vector<int>{1,2},"system int_vec");

stone::ConfigVar<std::list<int> >::ptr g_int_list_value_config =
    stone::Config::Lookup("system.int_list",std::list<int>{1,2},"system int_list");
    
stone::ConfigVar<std::set<int> >::ptr g_int_set_value_config =
    stone::Config::Lookup("system.int_set",std::set<int>{1,2},"system int_set");
    
stone::ConfigVar<std::unordered_set<int> >::ptr g_int_uset_value_config =
    stone::Config::Lookup("system.int_uset",std::unordered_set<int>{1,2},"system int_uset");

stone::ConfigVar<std::map<std::string,int> >::ptr g_str_int_map_value_config =
    stone::Config::Lookup("system.str_int_map",std::map<std::string,int>{{"k",2}},"system str_int_map");

stone::ConfigVar<std::unordered_map<std::string,int> >::ptr g_str_int_umap_value_config =
    stone::Config::Lookup("system.str_int_umap",std::unordered_map<std::string,int>{{"k",2}},"system str_int_umap");
void printf_yaml(const YAML::Node& node ,int level){
    if(node.IsScalar()){
        STONE_LOG_INFO(STONE_LOG_ROOT())<<std::string(level*4,' ')<<node.Scalar()<<" - "<<node.Type()<<" - "<<level;
    }else if(node.IsNull()){
       STONE_LOG_INFO(STONE_LOG_ROOT())<<std::string(level*4,' ')<<"Null - "<<node.Type()<<" - "<<level;
    }else if(node.IsMap()){
        for(auto iter=node.begin();
                 iter!=node.end();
                 ++iter){
       STONE_LOG_INFO(STONE_LOG_ROOT())<<std::string(level*4,' ')<<iter->first<<" - "<<iter->second.Type()<<" - "<<level;
       printf_yaml(iter->second,level+1);
        }
    }else if(node.IsSequence()){
        for(size_t i = 0;i<node.size();++i){
       STONE_LOG_INFO(STONE_LOG_ROOT())<<std::string(level*4,' ')<<i<<" - "<<node[i].Type()<<" - "<<level;
       printf_yaml(node[i],level+1);
        }
    }
}
void yaml_test(){
    YAML::Node root = YAML::LoadFile("../bin/conf/test.yml");
    printf_yaml(root,0);
}
void test_config(){
    STONE_LOG_INFO(STONE_LOG_ROOT())<<"before: "<<g_int_value_config->getValue();
    STONE_LOG_INFO(STONE_LOG_ROOT())<<"before: "<<g_float_value_config->toString();
#define XX(g_var,name,prefix) \
    { \
        auto& v =g_var->getValue(); \
        for(auto& i: v){ \
            STONE_LOG_INFO(STONE_LOG_ROOT())<<#prefix " " #name " : "<<i; \
        } \
        STONE_LOG_INFO(STONE_LOG_ROOT())<<#prefix " " #name " yaml : "<<g_var->toString(); \
    }

#define XX_M(g_var,name,prefix) \
    { \
        auto& v =g_var->getValue(); \
        for(auto& i: v){ \
            STONE_LOG_INFO(STONE_LOG_ROOT())<<#prefix " " #name " : {" \
            <<i.first<<","<<i.second<<"}"; \
        } \
        STONE_LOG_INFO(STONE_LOG_ROOT())<<#prefix " " #name " yaml : "<<g_var->toString(); \
    }
    XX(g_int_vec_value_config,int_vec,before);
    XX(g_int_list_value_config,int_list,before);
    XX(g_int_set_value_config,int_set,before);
    XX(g_int_uset_value_config,g_int_uset,before);
    XX_M(g_str_int_map_value_config,str_int_map,before);
    XX_M(g_str_int_umap_value_config,str_int_umap,before);
    YAML::Node root = YAML::LoadFile("../bin/conf/test.yml");
    stone::Config::LoadFromYaml(root);

    STONE_LOG_INFO(STONE_LOG_ROOT())<<"after: "<<g_int_value_config->getValue();
    STONE_LOG_INFO(STONE_LOG_ROOT())<<"after: "<<g_float_value_config->toString();
    
    XX(g_int_vec_value_config,int_vec,after);
    XX(g_int_list_value_config,int_list,after);
    XX(g_int_set_value_config,int_set,after);
    XX(g_int_uset_value_config,int_uset,after);
    XX_M(g_str_int_map_value_config,str_int_map,after);
    XX_M(g_str_int_umap_value_config,str_int_umap,after);
}
class Person{
public:
    std::string m_name;
    int m_age = 0;
    bool m_sex = 0;
    std::string toString() const {
        std::stringstream ss;
        ss << "[Person name = "<<m_name
           << " age = "<<m_age
           << " sex = "<<m_sex
           <<"]";
        return ss.str();
    }
    bool operator==(const Person& oth) const {
        return oth.m_name == m_name
               && oth.m_age == m_age
               && oth.m_sex == m_sex;
    }
};
namespace stone{
template<>
class LexicalCast<std::string,Person >{
public:
    Person operator()(const std::string& v){
        YAML::Node node =YAML::Load(v);
        Person p;
        p.m_name = node["name"].as<std::string>();
        p.m_age = node["age"].as<int>();
        p.m_sex = node["sex"].as<bool>();
        return p;
    }
};
template<>
class LexicalCast<Person,std::string>{
public:
    std::string operator()(const Person& p){
        YAML::Node node;
        node["name"]=p.m_name;
        node["age"]=p.m_age;
        node["sex"]=p.m_sex;
        std::stringstream ss;
        ss<<node;
        return ss.str();
    }
};


}
stone::ConfigVar<Person>::ptr g_person =
    stone::Config::Lookup("class.person",Person(),"system person");
void test_class(){
    STONE_LOG_INFO(STONE_LOG_ROOT())<<"before "<<g_person->getValue().toString()<<" - "<<g_person->toString();
    YAML::Node root = YAML::LoadFile("../bin/conf/test.yml");
    stone::Config::LoadFromYaml(root);

    

    STONE_LOG_INFO(STONE_LOG_ROOT())<<"after "<<g_person->getValue().toString()<<" - "<<g_person->toString();
}
void test_log(){
    static stone::Logger::ptr system_log = STONE_LOG_NAME("system");
    STONE_LOG_INFO(system_log)<<"hello system"<<std::endl;
    std::cout<<stone::LoggerMgr::GetInstance()->toYamlString()<<std::endl;
    YAML::Node root = YAML::LoadFile("../bin/conf/test.yml");
    stone::Config::LoadFromYaml(root);
    std::cout<<"================================"<<std::endl;

    std::cout<< stone::LoggerMgr::GetInstance()->toYamlString()<<std::endl;
    std::cout<<"================================"<<std::endl;
    system_log->setFormatter("%d - %m%n");
    STONE_LOG_INFO(system_log)<<"hello system"<<std::endl;
}
int main()
{
    // STONE_LOG_INFO(STONE_LOG_ROOT())<<g_int_value_config->getValue();
    // STONE_LOG_INFO(STONE_LOG_ROOT())<<g_int_value_config->toString();
    // yaml_test();
    // test_config();
    // test_class();
    test_log();
    return 0;
}
