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
#include <queue>
using namespace std;

class ConnectionCache {
public:
    ConnectionCache(int);
    ~ConnectionCache();
    int read();
    int write(string &);
    queue<string>& getReadBuffQueue();
    time_t getCreateTime();
protected:
    void lockWrite();
    void unlockWrite();
private:
    char rbuf[16*1024];
    char wbuf[16*1024];
    queue<string> readbuff;
    int cfd;
    time_t create_time;
    pthread_mutex_t write_mutex;
};
#endif //WATERLILY_NET_CONNECTIONCACHE_H_
