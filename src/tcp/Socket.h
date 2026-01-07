//
// Created by redredmaple on 2025/10/29.
//

#ifndef MAIEV_SOCKET_H
#define MAIEV_SOCKET_H
#include <unistd.h>

namespace maiev{
    class Socket{
    public:
        Socket(){};
        ~Socket(){};

        void bind(int fd);
        void accept();
        void listen();
        void close();
    private:
        int mfd; //fd
    };
}

#endif //MAIEV_SOCKET_H

