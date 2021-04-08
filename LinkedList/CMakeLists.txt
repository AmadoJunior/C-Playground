cmake_minimum_required(VERSION 3.15)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinkedList
        LinkedList.cpp
        LinkedList.h
        main.cpp
        Node.cpp
        Node.h)
