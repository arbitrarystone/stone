#ifndef __STONE_LIBRARY_HPP__
#define __STONE_LIBRARY_HPP__
#include <memory>
#include "module.hpp"
namespace stone{
class Library{
public:
    static Module::ptr GetModule(const std::string& path);
};
}
#endif
