//
// ConnectionCache.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "net/ConnectionCache.h"

ConnectionCache::ConnectionCache(int fd) {
    memset(rbuf, 0, sizeof(rbuf));
    memset(wbuf, 0, sizeof(wbuf));
    cfd = fd;
    pthread_mutex_init(&write_mutex, NULL);
}

ConnectionCache::~ConnectionCache() {}

void ConnectionCache::lockWrite() {
    pthread_mutex_lock(&write_mutex);
}

void ConnectionCache::unlockWrite() {
    pthread_mutex_unlock(&write_mutex);
}

int ConnectionCache::read() {
    size_t size = recv(cfd, rbuf, sizeof(rbuf), 0);
    if(size <= 0) {
        return -1;
    }
    return 0;
}

int ConnectionCache::write(string &s) {
    if(s.size() <= 0) {
        return -1;
    }
    lockWrite();
    int wpos = 0;
    for(size_t i = 0; i < s.size(); ++i) {
        wbuf[i] = s[i];
        ++wpos;
    }
    wbuf[wpos] = '\0';
    size_t size = send(cfd, wbuf, sizeof(wbuf), 0);
    if((int)size < 0) {
        unlockWrite();
        return -1;
    }
    unlockWrite();
    return 0;
}
