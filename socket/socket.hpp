//
// Created by xiaowei003 on 2024/9/29.
//

#ifndef UNTITLED_SOCKET_HPP
#define UNTITLED_SOCKET_HPP

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

namespace maiev {
    class Socket {
    private:
        int _fd;
        unsigned int _port;
    public:
        Socket(unsigned int);

        Socket();

        void bind();

        void listen();

        int accept();

        void recv(int fd);

        void connect(char const *host, unsigned int);

        ssize_t send(char const *msg);

        int getFd() { return _fd; };

        ~Socket();
    };

    Socket::Socket() {
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        cout << "socket create :" << _fd << endl;
    }

    //create
    Socket::Socket(unsigned int port) {
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        _port = port;
        cout << "socket create :" << _fd << endl;
    }

    //bind
    void Socket::bind() {
        cout << "socket bind :" << _port << endl;
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(_port);

        int flag = ::bind(_fd, (struct sockaddr *) &addr, sizeof(addr));
        if (flag == -1) {
            throw runtime_error(std::string(strerror(errno)));
        }
    }

    //listen
    void Socket::listen() {
        cout << "socket listen:" << _fd << endl;
        int flag = ::listen(_fd, 3);
        if (flag == -1) {
            throw runtime_error("listen error:");
        }
    }

    //accept, rdy [send to /recv from ]client
    int Socket::accept() {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        cout << "socket accept:" << endl;
        socklen_t client_len = sizeof(addr);
        _client_fd = ::accept(_fd, (struct sockaddr *) &addr, &client_len);

        if (_client_fd == -1) {
            throw runtime_error("accept error:" + std::string(strerror(errno)));
        }

        return _client_fd;
    }

    //recv
    void Socket::recv(int fd) {
        char msg[1024] = {0};
        while (true) {
            ssize_t received = ::recv(fd, msg, sizeof(msg), 0);
            if (received == -1) {
                throw runtime_error("accept error:");
            }

            std::string recv_msg = std::string(msg, received);
            cout << "recv msg from :" << fd << "and msg:" << recv_msg << endl;
            recv_msg.erase(std::remove_if(recv_msg.begin(), recv_msg.end(), ::isspace),
                           recv_msg.end()); // Remove whitespace

            if (recv_msg.compare("end") == 0) {
                break;
            }

            std::fill(std::begin(msg), std::end(msg), 0);
        }
    }

    void Socket::connect(char const *host, unsigned int port) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, host, &addr.sin_addr);

        int flag = ::connect(_fd, (struct sockaddr *) &addr, sizeof(addr));

        if (flag == -1) {
            throw runtime_error("err" + std::string(strerror(errno)));
        }
    }

    ssize_t Socket::send(char const *message) {
        ssize_t send_bytes = ::send(_fd, message, strlen(message), 0);
        if (send_bytes < 0) {
            throw runtime_error("err:" + std::string(strerror(errno)));
        }

        cout << "send bytes : " << send_bytes << " to : fd" << _fd << endl;

        return send_bytes;
    }

    //unconnect
    Socket::~Socket() {
        cout << "~socket!" << endl;
        close(_fd);
    }
}


#endif //UNTITLED_SOCKET_HPP
