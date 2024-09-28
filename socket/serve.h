//
// Created by xiaowei003 on 2024/9/12.
//

#ifndef UNTITLED_SERVE_H
#define UNTITLED_SERVE_H

#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <cerrno>
#include <algorithm>
#include <exception>
using namespace std;

namespace maiev{
    class Socket{
    private:
        int _fd;
        unsigned int _port;
    public:
        Socket(unsigned int );
        void bind();
        void listen();
        int accept();
        void recv(int fd);
        void connect();
        int getFd() { return _fd;};
        ~Socket();
    };

    //create
    Socket::Socket(unsigned int port) {
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        _port = port;
        cout << "socket create :" << _fd << endl;
    }

    //bind
    void Socket::bind() {
        cout << "socket bind :" << port << endl;
        struct sockaddr_in addr;
        memset(&addr, 0 , sizeof(addr));
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);

        int flag = ::bind(_fd, (struct sockaddr*) &addr, sizeof(addr));
        if (flag == -1){
            throw exception(strerror(errno));
        }
    }

    //listen
    void Socket::listen() {
        cout << "socket listen:" << _fd << endl;
        int flag = ::listen(_fd, 3);
        if (flag == -1){
            throw exception("listen error:");
        }
    }

    //accept, rdy [send to /recv from ]client
    int Socket::accept() {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        cout << "socket accept:" << endl;
        socklen_t client_len = sizeof(addr);
        _fc = ::accept(_fd, (struct sockaddr*) & addr, &client_len);

        if (_fc == -1){
            throw exception("accept error:");
        }

        return _fd;
    }

    //recv
    void Socket::recv(int fd) {
        char msg[1024] = {0};
        while(true){
            ssize_t received = ::recv(fd, msg, sizeof(msg), 0);
            if (received == -1){
                throw exception("accept error:");
            }

            std::string recv_msg = std::string(msg, received);
            recv_msg.erase(std::remove_if(recv_msg.begin(), recv_msg.end(), ::isspace), recv_msg.end()); // Remove whitespace

            if (recv_msg.compare("end") == 0){
                break;
            }

            std::fill(std::begin(msg), std::end(msg), 0);
        }
    }

    //unconnect
    Socket::~Socket() {
        cout << "~socket!" << endl;
        close(_fd);
    }

    void test_socket()
    {
        try{
            Socket st(12340);
            st.bind();
            st.listen();
            int _fd = st.accept();
            st.recv(_fd);
        }catch(std::exception const & e){
            cout << "error:" << e.what() << endl;
        }
    }
}

int main()
{
    maiev::test_socket();
    return 0;
}
#endif //UNTITLED_SERVE_H
