cmake_minimum_required(VERSION 3.27)
project(Projekt_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_2 main.cpp
        "../../../Algo/Projekt 1/priority_queue.cpp"
        priority_queue_linked_list.cpp
        priority_queue_linked_list.h
        priority_queue_heap.cpp
        priority_queue_heap.h)
