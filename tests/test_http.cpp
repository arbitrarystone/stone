#include "src/http/http.hpp"

void test_request(){
    stone::http::HttpRequest::ptr req(new stone::http::HttpRequest);
    req->setHeader("host","www.baidu.com");
    req->setBody("hello stone");

    req->dump(std::cout)<<std::endl;
}

void test_response(){
    stone::http::HttpResponse::ptr rsp(new stone::http::HttpResponse);
    rsp->setHeader("X-X","stone");
    rsp->setBody("hello stone");

    rsp->setStatus((stone::http::HttpStatus)400);
    rsp->setClose(false);
    rsp->dump(std::cout)<<std::endl;
}
int main(int argc,char** argv){
    test_request();
    test_response();
    return 0;
}
