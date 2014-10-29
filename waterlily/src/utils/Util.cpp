//
// Util.cpp
// Created by hedongjie on 2014-10-29
// Copyright (c) 2014 jay2013
// The MIT License (MIT)

#include "utils/Util.h"

string trim(string str) {
    if(str.length() == 0) return str;
    string spaces = " \t\n\r";
    size_t start = str.find_first_not_of(spaces);
    size_t end = str.find_last_not_of(spaces);
    return str.substr(start, end - start + 1);
}

string intToString(int val) {
   ostringstream oss;
   oss<<val;
   return oss.str();
}

int stringToInt(string str) {
    return atoi(str.c_str());
}

vector<string> split(const string &str, char delim) {
    vector<string> elems;
    stringstream ss(str);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    while(!elems.empty() && elems.back().empty()) {
        elems.pop_back();
    }
    if(elems.empty()) {
        elems.push_back(str);
    }
    return elems;
}
