cmake_minimum_required(VERSION 3.29)
project(linkedtest)

set(CMAKE_CXX_STANDARD 20)

add_executable(linkedtest
        LinkedList.cpp
        LinkedList.h
        test.cpp
)
