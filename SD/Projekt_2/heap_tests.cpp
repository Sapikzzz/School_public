//
// Created by Jakub on 03.05.2024.
//

#include <iostream>
#include <chrono>
#include "priority_queue_heap.h"

void test_create_heap(int amount) {
    PriorityQueueHeap pqh;
    std::chrono::time_point<std::chrono::system_clock> cpu_start = std::chrono::system_clock::now();
    for (int i = 1; i <= amount; i++) {
        pqh.push(i, i);
    }
    std::chrono::time_point<std::chrono::system_clock> cpu_end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(cpu_end - cpu_start).count();
    std::cout << "Czas tworzenia kopca: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_push_heap(PriorityQueueHeap& pqh, int data, int priority) {
    // Write a function that measures the time of adding an element to the heap in nanoseconds
    std::chrono::time_point<std::chrono::system_clock> cpu_start = std::chrono::system_clock::now();
    pqh.push(data, priority);
    std::chrono::time_point<std::chrono::system_clock> cpu_end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(cpu_end - cpu_start).count();
    std::cout << "Czas dodawania elementu do kopca: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_extractMax_heap(PriorityQueueHeap& pqh){
    std::chrono::time_point<std::chrono::system_clock> cpu_start = std::chrono::system_clock::now();
    pqh.extractMax();
    std::chrono::time_point<std::chrono::system_clock> cpu_end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(cpu_end - cpu_start).count();
    std::cout << "Czas usuwania elementu z kopca: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_peek_heap(PriorityQueueHeap& pqh){
    std::chrono::time_point<std::chrono::system_clock> cpu_start = std::chrono::system_clock::now();
    pqh.peek();
    std::chrono::time_point<std::chrono::system_clock> cpu_end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(cpu_end - cpu_start).count();
    std::cout << "Czas podgladania elementu z kopca: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_modifyPriority_heap(PriorityQueueHeap& pqh, int data, int newPriority){
    std::chrono::time_point<std::chrono::system_clock> cpu_start = std::chrono::system_clock::now();
    pqh.modifyPriority(data, newPriority);
    std::chrono::time_point<std::chrono::system_clock> cpu_end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(cpu_end - cpu_start).count();
    std::cout << "Czas modyfikowania priorytetu elementu z kopca: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_getSize_heap(PriorityQueueHeap& pqh){
    std::chrono::time_point<std::chrono::system_clock> cpu_start = std::chrono::system_clock::now();
    pqh.getSize();
    std::chrono::time_point<std::chrono::system_clock> cpu_end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(cpu_end - cpu_start).count();
    std::cout << "Czas pobierania rozmiaru kopca: " << cpu_total_time_ns << " ns" << std::endl;
}


