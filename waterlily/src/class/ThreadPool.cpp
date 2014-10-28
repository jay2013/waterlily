//
// ThreadPool.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "class/ThreadPool.h"

ThreadPool::ThreadPool(int val) {
    capacity = val;
    threadpool.clear();
}
ThreadPool::~ThreadPool() {
    //TODO
}
bool ThreadPool::addThread() {
    if(threadpool.size() >= capacity) {
        return false;
    }
    LilyThread *tmpThread = new LilyThread();
    threadpool.push_back(tmpThread);
    return true;
}
