cmake_minimum_required(VERSION 3.15)
project(CCI_CH1_Problems)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CCI_CH1_Problems
        OneAway.cpp
        PalindromePermutations.cpp
        RotateMatrix.cpp
        Sets.cpp
        StringCompression.cpp
        URLify.cpp
        ZeroMatrix.cpp)

add_executable(ZeroMatrix ZeroMatrix.cpp)