cmake_minimum_required(VERSION 3.15)
project(BST)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Queue)

add_executable(BST
        Queue/Queue.cpp
        Queue/Queue.h
        BST.cpp
        BST.h
        main.cpp)
