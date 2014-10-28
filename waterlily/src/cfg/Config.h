//
// Config.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CFG_CONFIG_H_
#define WATERLILY_CFG_CONFIG_H_

#include <string>
using namespace std;

class Config {
public:
    Config();
    ~Config();
    int getBacklog();
    void setBacklog(int);
    string getAddress();
    void setAddress(string);
    int getListenPort();
    void setListenPort(int);
protected:
private:
    int backlog;
    string address;
    int listen_port;
    string cgi_root;
    string default_file;
    string document_root;
    string config_file;
    int max_client;
    int timeout;
};

#endif //WATERLILY_CFG_CONFIG_H_
