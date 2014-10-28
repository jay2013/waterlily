//
// Config.cpp
// Created by hedongjie on 2014-10-28
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "cfg/Config.h"

Config::Config() {}
Config::~Config() {}
int Config::getBacklog() {
    return backlog;
}
void Config::setBacklog(int val) {
    backlog = val;
}
