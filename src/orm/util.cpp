#include "util.hpp"
#include "src/util.hpp"
#include "src/util/hash_util.hpp"
namespace stone {
namespace orm {

std::string GetAsVariable(const std::string& v) {
    return stone::ToLower(v);
}

std::string GetAsClassName(const std::string& v) {
    auto vs = stone::split(v, '_');
    std::stringstream ss;
    for(auto& i : vs) {
        i[0] = toupper(i[0]);
        ss << i;
    }
    return ss.str();
}

std::string GetAsMemberName(const std::string& v) {
    auto class_name = GetAsClassName(v);
    class_name[0] = tolower(class_name[0]);
    return "m_" + class_name;
}

std::string GetAsGetFunName(const std::string& v) {
    auto class_name = GetAsClassName(v);
    return "get" + class_name;
}

std::string GetAsSetFunName(const std::string& v) {
    auto class_name = GetAsClassName(v);
    return "set" + class_name;
}

std::string XmlToString(const tinyxml2::XMLNode& node) {
    return "";
}

std::string GetAsDefineMacro(const std::string& v) {
    std::string tmp = stone::replace(v, '.', '_');
    tmp = stone::ToUpper(tmp);
    return "__" + tmp + "__";
}

}
}

