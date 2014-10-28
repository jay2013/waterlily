//
// LilyThread.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CLASS_LILYTHREAD_H_
#define WATERLILY_CLASS_LILYTHREAD_H_

#include <pthread.h>

class LilyThread {
public:
    LilyThread();
    ~LilyThread();
protected:
private:
    pthread_t th;
    int status;
    pthread_mutex_t mutex;
};
#endif //WATERLILY_CLASS_LILYTHREAD_H_
