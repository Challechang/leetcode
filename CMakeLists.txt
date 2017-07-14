cmake_minimum_required(VERSION 3.7)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Solution.cpp Solution.h)
add_executable(leetcode ${SOURCE_FILES})