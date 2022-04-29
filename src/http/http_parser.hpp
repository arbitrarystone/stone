#ifndef __STONE_HTTP_PARSER_HPP__
#define __STONE_HTTP_PARSER_HPP__
#include "http.hpp"
#include "http11_parser.h"
#include "httpclient_parser.h"
namespace stone{
namespace http{

class HttpRequestParser{
public:
    typedef std::shared_ptr<HttpRequestParser> ptr;
    HttpRequestParser();

    size_t execute(char* data,size_t len);
    size_t execute(char* data, size_t len, bool chunck);
    int isFinished();
    int hasError();

    HttpRequest::ptr getData() const { return m_data;}

    void setError(int error) { m_error = error;}
    
    uint64_t getContentLength() const;
    const http_parser& getParser() const { return m_parser;}
public:
    static uint64_t GetHttpRequestBufferSize();
    static uint64_t GetHttpRequestMaxBodySize();
private:
    http_parser m_parser;
    HttpRequest::ptr m_data;
    int m_error;
};

class HttpResponseParser{
public:
    typedef std::shared_ptr<HttpResponseParser> ptr;
    HttpResponseParser();

    size_t execute(char* data,size_t len);
    size_t execute(char* data, size_t len, bool chunck);
    int isFinished();
    int hasError();
    uint64_t getContentLength() const;

    HttpResponse::ptr getData() const { return m_data;}

    void setError(int error) { m_error = error;}
    const httpclient_parser& getParser() const { return m_parser;}
public:
    static uint64_t GetHttpResponseBufferSize();
    static uint64_t GetHttpResponseMaxBodySize();

private:
    httpclient_parser m_parser;
    HttpResponse::ptr m_data;
    int m_error;
};


}
}
#endif
