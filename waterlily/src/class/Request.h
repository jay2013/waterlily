//
// Request.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CLASS_REQUEST_H_
#define WATERLILY_CLASS_REQUEST_H_

#include <string>
#include "common/Const.h"
using namespace std;
class Request {
public:
    Request();
    ~Request();
protected:
private:
    request_t request_type;
    string head;
    string uri; 
    string rpath; //file path
    unsigned long major; //version number
    unsigned long minor; 
    int err; //error code
};
#endif //WATERLILY_CLASS_REQUEST_H_
