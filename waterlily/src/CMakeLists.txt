#
# CMakeLists file
# Created by hedongjie on 2014-10-27.
# Copyright (c) 2014 jay2013
# The MIT License (MIT)

cmake_minimum_required(VERSION 2.6)

project(waterlily)

SET(CMAKE_CXX_FLAGS_DEBUG "-g -fno-strict-aliasing -ggdb -Wall -Wl,--hash-style=sysv")

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(cfg)
add_subdirectory(net)
add_subdirectory(tests)

add_executable(test.e tests/test_init_socket.cpp)
target_link_libraries(test.e cfg net test)

