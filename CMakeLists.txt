cmake_minimum_required(VERSION 3.21)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp)

add_executable(LinearList LinearList/static_linear_list.cpp)
add_executable(dynamic_linear_list LinearList/dynamic_linear_list.cpp)