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
