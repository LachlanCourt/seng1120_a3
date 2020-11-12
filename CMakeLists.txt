cmake_minimum_required(VERSION 3.17)
project(Assignment3)

set(CMAKE_CXX_STANDARD 98)

include_directories(.)

add_executable(Assignment3
        BSTree.h
        BSTree.hpp
        BTNode.h
        BTNode.hpp
        HTable.h
        HTable.hpp
        TreeHashTableDemo.cpp)
