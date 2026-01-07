//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_HTTP_H
#define MAIEV_HTTP_H
#include <iostream>
#include <string>

using std::string;
using std::cout;

struct HttpCode{
    int code;
    string msg;
};

struct Http{
protected:
    HttpCode httpcode;
};

class HttpResponse : Http{
public:
    HttpResponse(){}
};

class HttpRequest : Http{
public:
    HttpRequest(){}
    template<typename T>
    Result<T> get(string url);
    template<typename T>
    Result<T> post(string url, T mode);
private:
    string path;
    string url;
    string queryParam;
};

template<typename T>
Result<T> HttpRequest::get(string url) {
    std::cout << "url: " << url << std::endl;
    Result<T> result ;
    return result;
}

template<typename T>
Result<T> HttpRequest::post(string url, T mode) {
    cout << "mode: " << endl;
    Result<T> result;
    return result;
}


#endif //MAIEV_HTTP_H
