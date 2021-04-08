cmake_minimum_required(VERSION 3.15)
project(Dijkstras)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(tools)

add_executable(Dijkstras
        tools/PriorityQueue.cpp
        tools/PriorityQueue.h
        main.cpp
        WeightedGraph.cpp
        WeightedGraph.h)
