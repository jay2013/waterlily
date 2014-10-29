//
// LilyThread.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "class/LilyThread.h"

LilyThread::LilyThread() {
    status = DETACHED;
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_lock(&mutex);
}

LilyThread::~LilyThread() {
    pthread_mutex_destroy(&mutex);
    if(status != DETACHED) {
    }
}
