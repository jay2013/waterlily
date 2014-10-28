//
// NetHandler.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "net/NetHandler.h"

extern Config config;
NetHandler::NetHandler(RequestQueue * val) {
    listener_fd = -1;
    FD_ZERO(&fdset);
    req_queue = val;
}
NetHandler::~NetHandler() {}
void NetHandler::test() {
    int ret = init_socket("192.168.1.118", 2048);
    if(ret == -1) cout<<"error"<<endl;
    if(ret == 0) cout<<"right!"<<endl;
}
void NetHandler::run() {
    int ret = init_socket(config.getAddress(), config.getListenPort());
    if(ret == -1) {
        cout<<"init socket failed!"<<endl;
        return;
    }
    FD_SET(listener_fd, &fdset);
    fd_set readFd;
    int fd_max = listener_fd;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    for(;;) {
        readFd = fdset;
        int count = select(fd_max + 1, &readFd, NULL, NULL, &timeout);
        if(count == -1) {
            cout<<"select error!"<<endl;
            return;
        } else if(count == 0) {
            continue;
        } else {
            for(int i = 0; i <= fd_max; ++i) {
                if(i == listener_fd) {
                    struct sockaddr_in sa;
                    socklen_t slen = sizeof(sa);
                    int new_fd = accept(i, (struct sockaddr *)&sa, &slen);
                    if(new_fd == -1) {
                        cout<<"accept error!"<<endl;
                    } else {
                        FD_SET(new_fd, &fdset);
                        if(new_fd > fd_max) {
                            fd_max = new_fd;
                        }
                        addConnection(new_fd);
                    }
                } else {
                    cout<<"hello world!"<<endl;
                    ConnectionCache * cache = getConnectionByFd(i);
                    if(cache != NULL) {
                        ret =  cache->read();
                        if(ret == 0) {
                            queue<string>& tmp = cache->getReadBuffQueue();
                            while(!tmp.empty()) {
                                cout<<tmp.front()<<endl;
                                tmp.pop();
                            }
                        }
                        if(ret == -1) {
                            closeConnection(i);
                        }
                    }
                }
            } //for
        }
    } //for(;;)
}
void NetHandler::showStatus() {
    cout<<"##################################"<<endl;
    cout<<"NetHandlerStatus:"<<endl;
    cout<<"Num of Cache:"<<fd_cache.size()<<endl;
    cout<<"#################################"<<endl;
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

ConnectionCache * NetHandler::addConnection(int fd) {
    ConnectionCache * cache = new ConnectionCache(fd);    
    fd_cache.insert(make_pair(fd, cache));
    return cache;
}

ConnectionCache * NetHandler::getConnectionByFd(int fd) {
    map<int, ConnectionCache *>::const_iterator it = fd_cache.find(fd);
    if(it != fd_cache.end()) {
        return it->second;
    } else {
        return NULL;
    }
}

void NetHandler::removeConnection(int fd) {
    ConnectionCache * cache = getConnectionByFd(fd);
    if(cache != NULL) {
        fd_cache.erase(fd);
        delete cache;
    }
}

void NetHandler::closeConnection(int fd) {
    if(fd > 0) {
        FD_CLR(fd, &fdset);
        close(fd);
        shutdown(fd, SHUT_RDWR);
        removeConnection(fd);
    }
}

void NetHandler::cleanZombieConnection(size_t time) {
    for(map<int, ConnectionCache *>::iterator it = fd_cache.begin();
        it != fd_cache.end();) {
        if(time - it->second->getCreateTime() >= 30) {
            FD_CLR(it->first, &fdset);
            shutdown(it->first, SHUT_RDWR);
            delete it->second;
            fd_cache.erase(it++);
        } else {
            ++it;
        }    
    }
}

