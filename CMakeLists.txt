cmake_minimum_required(VERSION 3.21)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp)

add_executable(LinearList LinearList/static_linear_list.cpp)
add_executable(dynamic_linear_list LinearList/dynamic_linear_list.cpp)
add_executable(link_list LinkList/link_list.cpp)
add_executable(link_list_with_head LinkList/link_list_with_head.cpp)
add_executable(double_link_list LinkList/double_link_list.cpp)
add_executable(simple_pattern_matching_algorithm String/simple_pattern_matching_algorithm.cpp)