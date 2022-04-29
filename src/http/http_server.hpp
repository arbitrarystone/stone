#ifndef __STONE_HTTP_SERVER_HPP__
#define __STONE_HTTP_SERVER_HPP__
#include "src/tcp_server.hpp"
#include "http_session.hpp"
#include "servlet.hpp"
namespace stone{
namespace http{
class HttpServer : public TcpServer{
public:
    typedef std::shared_ptr<HttpServer> ptr;
    HttpServer(bool keepalive = false
               ,stone::IOManager* worker = stone::IOManager::GetThis()
               ,stone::IOManager* io_worker = stone::IOManager::GetThis()
               ,stone::IOManager* accept_worker = stone::IOManager::GetThis());

    ServletDispatch::ptr getServletDispatch() const { return m_dispatch;}

    void setServletDispatch(ServletDispatch::ptr v) { m_dispatch = v;}

protected:
    virtual void handleClient(Socket::ptr client) override;
private:
    bool m_isKeepalive;
    ServletDispatch::ptr m_dispatch;
};
}
}
#endif
