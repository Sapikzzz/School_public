cmake_minimum_required(VERSION 3.27)
project(Projekt_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_1 main.cpp
        linked_list.h
        linked_list.cpp
        test_linked_list.h
        test_linked_list.cpp
        dynamic_array.cpp
        dynamic_array.h
        test_dynamic_array.cpp
        test_dynamic_array.h
)
