//
// NetHandler.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_NET_NETHANDLER_H_
#define WATERLILY_NET_NETHANDLER_H_

#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>

#include "cfg/Config.h"
using namespace std;

class NetHandler {
public:
    NetHandler();
    ~NetHandler();
    void test();
    void run();
protected:
    int init_socket(const string address, const int port);
private:
    int listener_fd;
    fd_set fdset;
};

#endif //WATERLILY_NET_NETHANDLER_H_
