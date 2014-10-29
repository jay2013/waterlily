//
// Config.h
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#ifndef WATERLILY_CFG_CONFIG_H_
#define WATERLILY_CFG_CONFIG_H_

#include <iostream>
#include <fstream>
#include <string>

#include "utils/Util.h"
using namespace std;

class Config {
public:
    Config();
    ~Config();
    void readCfgFile(string);
    int getBacklog();
    void setBacklog(int);
    string getAddress();
    void setAddress(string);
    int getListenPort();
    void setListenPort(int);
    string getCgiRoot();
    void setCgiRoot(string);
    string getDefaultFile();
    void setDefaultFile(string);
    string getDocumentRoot();
    void setDocumentRoot(string);
    string getConfigFile();
    void setConfigFile(string);
    int getMaxClient();
    void setMaxClient(int);
    int getTimeout();
    void setTimeout(int);
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
