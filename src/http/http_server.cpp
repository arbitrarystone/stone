#include "http_server.hpp"
#include "src/log.hpp"
namespace stone{
namespace http{
static stone::Logger::ptr g_logger = STONE_LOG_NAME("system");
HttpServer::HttpServer(bool keepalive
               ,stone::IOManager* worker
               ,stone::IOManager* io_worker
               ,stone::IOManager* accept_worker)
    :TcpServer(worker,io_worker,accept_worker)
    ,m_isKeepalive(keepalive){
        m_dispatch.reset(new ServletDispatch);

}

void HttpServer::handleClient(Socket::ptr client){
    STONE_LOG_DEBUG(g_logger) << "handleClient" << *client;

    HttpSession::ptr session(new HttpSession(client));
    do{
        auto req = session->recvRequest();
        if(!req){
            STONE_LOG_WARNING(g_logger)<<"recv http request errno="
                <<errno<<" strerr="<<strerror(errno)
                <<" client:"<<*client << " keep_alive=" << m_isKeepalive;
            break;
        }
        HttpResponse::ptr rsp(new HttpResponse(req->getVersion(),req->isClose() || !m_isKeepalive));

        rsp->setHeader("Server",getName());
        m_dispatch->handle(req,rsp,session);
        session->sendResponse(rsp);

        if(!m_isKeepalive || req->isClose()){
            break;
        }
    }while(true);

    session->close();
}





}
}
