//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_APPLICATION_H
#define MAIEV_APPLICATION_H

#include "Mvc.h"
#include "Http.h"
#include "../entity/User.h"

class Application{
public:
    Application(string name): _name(name){
    }
    void start(HttpRequest request, HttpResponse response);
private:
    Controller _controller;
    View _view;
    string _name;
    HttpResponse _response;
    HttpRequest _request;
};

void Application::start(HttpRequest request, HttpResponse response) {
    _request = request;
    _response = response;
}

#endif //MAIEV_APPLICATION_H
