cmake_minimum_required(VERSION 3.12)
project(test)

set(CMAKE_CXX_STANDARD 11)

set(dir
        ./vector
        ./list
        )

include_directories(${dir})

add_executable(test_vector test_vector.cpp)
add_executable(test_list test_list.cpp)