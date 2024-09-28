//
// Created by xiaowei003 on 2024/9/12.
//
#include "client.h"
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

int xx()
{
    struct sockaddr_in addr;
    char buff[1024] = {0};

    //create
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd < 0){
        perror("create error");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12340);
    //addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    //connect
    if (connect(fd, (struct sockaddr*) &addr, sizeof(addr)) < 0){
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    printf("connect OK\n");

    ssize_t bytes_read = read(fd, buff, sizeof(buff) - 1);
    if (bytes_read < 0) {
        perror("read error");
        close(fd);
        exit(EXIT_FAILURE);
    }

    buff[bytes_read] = '\0';

    //send

    cout<<"read from :::" << buff << endl;

    //close
    close(fd);

    return 0;
}

