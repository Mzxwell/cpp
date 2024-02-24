cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp main.cpp)
add_executable(solution solution.cpp
        solution.h)
add_executable(DBit DBit.cpp)
add_executable(link link.cpp)
add_executable(BLL BLL.cpp)
add_executable(plus plus.cpp)
add_executable(mali mali.cpp)
add_executable(slj slj.cpp)
add_executable(3lj 3lj.cpp)
add_executable(Puzzle Puzzle.cpp)
add_executable(puzzle0 puzzle0.cpp)
