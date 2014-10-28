//
// Config.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CFG_CONFIG_H_
#define WATERLILY_CFG_CONFIG_H_

class Config {
public:
    Config();
    ~Config();
    int getBacklog();
    void setBacklog(int);
protected:
private:
    int backlog;
};

#endif //WATERLILY_CFG_CONFIG_H_
