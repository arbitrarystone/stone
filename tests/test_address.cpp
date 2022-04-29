#include "src/address.hpp"
#include "src/log.hpp"

stone::Logger::ptr g_logger = STONE_LOG_ROOT();

void test() {
    std::vector<stone::Address::ptr> addrs;

    STONE_LOG_INFO(g_logger) << "begin";
    //bool v = stone::Address::Lookup(addrs, "localhost:3080");
    bool v = stone::Address::Lookup(addrs, "www.baidu.com", AF_INET);
    //bool v = stone::Address::Lookup(addrs, "www.stone.top", AF_INET);
    STONE_LOG_INFO(g_logger) << "end";
    if(!v) {
        STONE_LOG_ERROR(g_logger) << "lookup fail";
        return;
    }

    for(size_t i = 0; i < addrs.size(); ++i) {
        STONE_LOG_INFO(g_logger) << i << " - " << addrs[i]->toString();
    }

    stone::Address::ptr addr = stone::Address::LookupAny("localhost:4080");
    if(addr) {
        stone::Address* a = addr.get();
        STONE_LOG_DEBUG(g_logger) <<a->toString();
    } else {
        STONE_LOG_ERROR(g_logger) << "error";
    }
}

void test_iface() {
    std::multimap<std::string, std::pair<stone::Address::ptr, uint32_t> > results;

    bool v = stone::Address::GetInterfaceAddresses(results);
    if(!v) {
        STONE_LOG_ERROR(g_logger) << "GetInterfaceAddresses fail";
        return;
    }

    for(auto& i: results) {
        STONE_LOG_INFO(g_logger) << i.first << " - " << i.second.first->toString() << " - "
            << i.second.second;
    }
}

void test_ipv4() {
    auto addr = stone::IPAddress::Create("www.sylar.top");
    //auto addr = stone::IPAddress::Create("127.0.0.8");
    if(addr) {
        STONE_LOG_INFO(g_logger) << addr->toString();
    }
}

int main(int argc, char** argv) {
    test_ipv4();
    test_iface();
    test();
    return 0;
}
