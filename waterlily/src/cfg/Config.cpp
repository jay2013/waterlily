//
// Config.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "cfg/Config.h"

Config::Config() {
    backlog = 1024;
    address = "127.0.0.1";
    listen_port = 2048;
    cgi_root = "/var/www/cgi-bin/";
    default_file = "index.htm";
    document_root = "/var/www/";
    config_file = "/etc/waterlily.cfg";
    max_client = 10;
    timeout = 30;
}
Config::~Config() {}
int Config::getBacklog() {
    return backlog;
}
void Config::readCfgFile(string file) {
    ifstream ifs(file.c_str());
    if(!ifs) {
        cout<<"open file failed"<<endl;
        return;
    }
    setConfigFile(file);
    string line;
    while(getline(ifs, line)) {
        cout<<line<<endl;
        line = trim(line);
        if(line.length() == 0) continue;
        if(line[0] == '#') continue;
        if(line.find("=") == line.npos) {
            cout<<"config file illegal!"<<endl;
            return;
        }
        vector<string> elems = split(line, '=');
        if(elems.size() != 2) {
            cout<<"config file illegal!"<<endl;
            return;
        }
        for(size_t i = 0; i < elems.size(); ++i) {
            elems[i] = trim(elems[i]);
        }
        if(elems[0] == "backlog") {
            setBacklog(stringToInt(elems[1])); 
        } else if(elems[0] == "address") {
            setAddress(elems[1]);
        } else if(elems[0] == "listen_port") {
            setListenPort(stringToInt(elems[1]));
        } else if(elems[0] == "cgi_root") {
            setCgiRoot(elems[1]);
        } else if(elems[0] == "default_file") {
            setDefaultFile(elems[1]);
        } else if(elems[0] == "config_file") {
            setConfigFile(elems[1]);
        } else if(elems[0] == "document_root") {
            setDocumentRoot(elems[1]);
        } else if(elems[0] == "max_client") {
            setMaxClient(stringToInt(elems[1]));
        } else if(elems[0] == "timeout") {
            setTimeout(stringToInt(elems[1]));
        } else {
            cout<<"config file illegal!"<<endl;
            return;
        }
    }
}
void Config::setBacklog(int val) {
    backlog = val;
}
string Config::getAddress() {
    return address;
}
void Config::setAddress(string val) {
    address = val;
}
int Config::getListenPort() {
    return listen_port;
}
void Config::setListenPort(int val) {
    listen_port = val;
}
string Config::getCgiRoot() {
    return cgi_root;
}
void Config::setCgiRoot(string val) {
    cgi_root = val;
}
string Config::getDefaultFile() {
    return default_file;
}
void Config::setDefaultFile(string val) {
    default_file = val;
}
string Config::getDocumentRoot() {
    return document_root;
}
void Config::setDocumentRoot(string val) {
    document_root = val;
}
string Config::getConfigFile() {
    return config_file;
}
void Config::setConfigFile(string val) {
    config_file = val;
} 
int Config::getMaxClient() {
    return max_client;
}
void Config::setMaxClient(int val) {
    max_client = val;
}
int Config::getTimeout() {
    return timeout;    
}
void Config::setTimeout(int val) {
    timeout = val;
}
