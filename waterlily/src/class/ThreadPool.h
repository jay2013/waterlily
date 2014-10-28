//
// ThreadPool.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CLASS_THREADPOOL_H_
#define WATERLILY_CLASS_THREADPOOL_H_

#include <vector>

#include "class/LilyThread.h"

using namespace std;
class ThreadPool {
public:
    ThreadPool(int);
    ~ThreadPool();
    bool addThread();
protected:
private:
    vector<LilyThread *> threadpool;
    int capacity;
};
#endif //WATERLILY_CLASS_THREADPOOL_H_
