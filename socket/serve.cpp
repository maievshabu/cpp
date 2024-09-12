//
// Created by xiaowei003 on 2024/9/12.
//

#include "serve.h"
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int xx(void)
{

//create
    int fd_s, fd_c;

    char buffersize[1024] = {0};
    struct sockaddr_in addr_s, addr_c;
    socklen_t client_len = sizeof(addr_c);

    fd_s = socket(AF_INET, SOCK_STREAM, 0);
    if (fd_s == -1){
        perror("socket failed!");
        exit(EXIT_FAILURE);
    }

    memset(&addr_s, 0, sizeof(addr_s));
    memset(&addr_c, 0, sizeof(addr_c));

    addr_s.sin_addr.s_addr = INADDR_ANY;
    addr_s.sin_family = AF_INET;
    addr_s.sin_port = htons(12340);

    //bind
    if (bind(fd_s, (struct sockaddr *)&addr_s, sizeof(addr_s)) < 0){
        perror("bind error");
        close(fd_s);
        exit(EXIT_FAILURE);
    }

    //listen
    if (listen(fd_s, 3) < 0){
        perror("listen error");
        close(fd_s);
        exit(EXIT_FAILURE);
    }

    printf("Waiting for conections...\n");
    //accept
    fd_c = accept(fd_s, (struct sockaddr *)&addr_c, &client_len);
    if (fd_c < 0){
        perror("bind error");
        close(fd_s);
        exit(EXIT_FAILURE);
    }

    //recv, send
    strcpy(buffersize, "Hello world from Serve!!");
    send(fd_c, buffersize, sizeof(buffersize), 0);

    //close
    close(fd_s);
    close(fd_c);

    return 0;
}

