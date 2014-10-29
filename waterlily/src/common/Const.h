//
// Const.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_COMMON_CONST_H_
#define WATERLILY_COMMON_CONST_H_

typedef int request_t;

enum REQUEST_TYPE {
    REQUEST_TYPE_GET = 0,
    REQUEST_TYPE_POST = 1,
    REQUEST_TYPE_PUT = 2,
    REQUEST_TYPE_DELETE = 3,
    REQUEST_TYPE_HEAD = 4,
};

enum THREAD_STATUS {
    IDLE = 0,
    RUNNING = 1,
    DETACHED = 2,
};

#endif //WATERLILY_COMMON_CONST_H_
