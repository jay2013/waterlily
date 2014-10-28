//
// NetHandler.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "net/NetHandler.h"

extern Config config;
NetHandler::NetHandler() {
    listener_fd = -1;
}
NetHandler::~NetHandler() {}
void NetHandler::test() {
    int ret = init_socket("192.168.1.118", 2048);
    if(ret == -1) cout<<"error"<<endl;
    if(ret == 0) cout<<"right!"<<endl;
}
int NetHandler::init_socket(const string address, const int port)
{
    listener_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listener_fd == -1) {
        cout<<"socket call failed!"<<endl;
        return -1;
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &addr.sin_addr);
    addr.sin_port = htons(port);
    int ret = bind(listener_fd, (struct sockaddr *)&addr, sizeof(addr));
    if(ret == -1) {
        close(listener_fd);
        cout<<"bind call failed!"<<endl;
        return -1;
    }
    cout<<config.getBacklog()<<endl;
    ret = listen(listener_fd, config.getBacklog());
    if(ret == -1) {
        close(listener_fd);
        cout<<"listen call failed!"<<endl;
        return -1;
    }
    cout<<listener_fd<<endl;
    return 0;
}
