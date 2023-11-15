cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp main.cpp)
add_executable(solution solution.cpp
        solution.h)
add_executable(DBit DBit.cpp)
add_executable(link link.cpp)
add_executable(BLL BLL.cpp)