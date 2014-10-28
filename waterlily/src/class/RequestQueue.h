//
// RequestQueue.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CLASS_REQUESTQUEUE_H_
#define WATERLILY_CLASS_REQUESTQUEUE_H_

#include <pthread.h>
#include <queue>
#include "class/Request.h"

class RequestQueue {
public:
    RequestQueue();
    ~RequestQueue();
    void pushRequest(Request *);
protected:
    void lockMutex();
    void unlockMutex();
private:
    queue<Request *> req_queue;
    pthread_mutex_t request_queue_mutex;
};

#endif //WATERLILY_CLASS_REQUESTQUEUE_H_
