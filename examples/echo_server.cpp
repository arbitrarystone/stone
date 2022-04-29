#include "src/tcp_server.hpp"
#include "src/iomanager.hpp"
#include "src/log.hpp"

#include "src/address.hpp"
#include "src/bytearray.hpp"

static stone::Logger::ptr g_logger = STONE_LOG_ROOT();

class EchoServer : public stone::TcpServer{
public:
    EchoServer(int type);
    void handleClient(stone::Socket::ptr client);

private:
    int m_type = 0;
};

EchoServer::EchoServer(int type)
    :m_type(type){
}

void EchoServer::handleClient(stone::Socket::ptr client){
    STONE_LOG_INFO(g_logger)<<"handleClient "<<*client;
    stone::ByteArray::ptr ba(new stone::ByteArray);
    while(true){
        ba->clear();
        std::vector<iovec> iovs;
        ba->getWriteBuffers(iovs,1024);

        std::vector<iovec> io;
        
        int rt = client->recv(&iovs[0],iovs.size());
        if(rt == 0){
            STONE_LOG_INFO(g_logger)<<"client close: "<<*client;
            break;
        }else if(rt < 0){
            STONE_LOG_ERROR(g_logger)<<"client error rt ="<<rt
                <<" errno="<<errno<<" errstr="<<strerror(errno);
            break;
        }

        ba->setPosition(ba->getPosition() + rt);

        ba->setPosition(0);
        if(m_type == 1){
            STONE_LOG_INFO(g_logger)<<ba->toString();
        }else{
            STONE_LOG_INFO(g_logger)<<ba->toHexString();
        }
    }
    
}

int type = 1;
void run(){
    EchoServer::ptr es(new EchoServer(type));

    auto addr = stone::Address::LookupAny("0.0.0.0:8020");
    while(!es->bind(addr)){
        sleep(2);
    }
    es->start();
}
int main(int argc,char** argv){
    if(argc < 2){
        STONE_LOG_INFO(g_logger)<< "used as["<<argv[0]<<" -t] or ["<<argv[0]<<" -b]";
        return 0;
    }
    if(!strcmp(argv[1],"-b")){
        type = 2;
    }
    stone::IOManager iom(2);
    iom.schedule(&run);
    return 0;
}
