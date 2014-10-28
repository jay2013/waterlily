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
#include <map>
#include <string>

#include "cfg/Config.h"
#include "net/ConnectionCache.h"
#include "class/RequestQueue.h"
using namespace std;

class NetHandler {
public:
    NetHandler(RequestQueue *);
    ~NetHandler();
    void test();
    void run();
    void showStatus();
protected:
    int init_socket(const string address, const int port);
    ConnectionCache * addConnection(int fd);
    ConnectionCache * getConnectionByFd(int fd);
    void removeConnection(int fd);
    void closeConnection(int fd);
    void cleanZombieConnection(size_t time);
private:
    map<int, ConnectionCache *> fd_cache;
    RequestQueue * req_queue;
    int listener_fd;
    fd_set fdset;
};

#endif //WATERLILY_NET_NETHANDLER_H_
