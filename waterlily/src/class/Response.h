//
// Response.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CLASS_RESPONSE_H_
#define WATERLILY_CLASS_RESPONSE_H_

#include <sys/types.h>
#include <sys/stat.h>

#include "common/Const.h"

class Response {
public:
    Response();
    ~Response();
protected:
private:
    request_t type;
    time_t create_time;
    time_t expire_time;
    int status;
    int content_length;
    int fd;
    struct stat fstat;
};

#endif //WATERLILY_CLASS_RESPONSE_H_
