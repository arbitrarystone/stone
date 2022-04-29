#include "table.hpp"
#include "src/util.hpp"
#include "src/log.hpp"
#include "src/util/hash_util.cpp"

static stone::Logger::ptr g_logger = STONE_LOG_NAME("orm");

void gen_cmake(const std::string& path, const std::map<std::string, stone::orm::Table::ptr>& tbs) {
    std::ofstream ofs(path + "/CMakeLists.txt");
    ofs << "cmake_minimum_required(VERSION 3.0)" << std::endl;
    ofs << "project(orm_data)" << std::endl;
    ofs << std::endl;
    ofs << "set(LIB_SRC" << std::endl;
    for(auto& i : tbs) {
        ofs << "    " << stone::replace(i.second->getNamespace(), ".", "/")
            << "/" << stone::ToLower(i.second->getFilename()) << ".cc" << std::endl;
    }
    ofs << ")" << std::endl;
    ofs << "add_library(orm_data ${LIB_SRC})" << std::endl;
    ofs << "force_redefine_file_macro_for_sources(orm_data)" << std::endl;
}


int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "use as[" << argv[0] << " orm_config_path orm_output_path]" << std::endl;
    }

    std::string out_path = "./orm_out";
    std::string input_path = "bin/orm_conf";
    if(argc > 1) {
        input_path = argv[1];
    }
    if(argc > 2) {
        out_path = argv[2];
    }
    std::vector<std::string> files;
    stone::FSUtil::ListAllFile(files, input_path, ".xml");
    std::vector<stone::orm::Table::ptr> tbs;
    bool has_error = false;
    for(auto& i : files) {
        STONE_LOG_INFO(g_logger) << "init xml=" << i << " begin";
        tinyxml2::XMLDocument doc;
        if(doc.LoadFile(i.c_str())) {
            STONE_LOG_ERROR(g_logger) << "error: " << doc.ErrorStr();
            has_error = true;
        } else {
            stone::orm::Table::ptr table(new stone::orm::Table);
            if(!table->init(*doc.RootElement())) {
                STONE_LOG_ERROR(g_logger) << "table init error";
                has_error = true;
            } else {
                tbs.push_back(table);
            }
        }
        STONE_LOG_INFO(g_logger) << "init xml=" << i << " end";
    }
    if(has_error) {
        return 0;
    }

    std::map<std::string, stone::orm::Table::ptr> orm_tbs;
    for(auto& i : tbs) {
        i->gen(out_path);
        orm_tbs[i->getName()] = i;
    }
    gen_cmake(out_path, orm_tbs);
    return 0;
}

