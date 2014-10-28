//
// ConnectionCache.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_NET_CONNECTIONCACHE_H_
#define WATERLILY_NET_CONNECTIONCACHE_H_

#include <string.h>
#include <sys/socket.h>
#include <string>
using namespace std;

class ConnectionCache {
public:
    ConnectionCache(int);
    ~ConnectionCache();
    int read();
    int write(string &);
protected:
    void lockWrite();
    void unlockWrite();
private:
    char rbuf[16*1024];
    char wbuf[16*1024];
    int cfd;
    pthread_mutex_t write_mutex;
};
#endif //WATERLILY_NET_CONNECTIONCACHE_H_
