//
// RequestQueue.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "class/RequestQueue.h"

RequestQueue::RequestQueue() {
    pthread_mutex_t request_queue_mutex;
    while(!req_queue.empty()) {
        req_queue.pop();
    }
}

RequestQueue::~RequestQueue() {
    pthread_mutex_destroy(&request_queue_mutex);
}

void RequestQueue::pushRequest(Request * req) {
    lockMutex();
    req_queue.push(req);
    unlockMutex();
}

void RequestQueue::lockMutex() {
    pthread_mutex_lock(&request_queue_mutex);
}

void RequestQueue::unlockMutex() {
    pthread_mutex_unlock(&request_queue_mutex);
}
