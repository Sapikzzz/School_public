//
// Created by Jakub on 03.05.2024.
//

#include <iostream>
#include <chrono>
#include "priority_queue_linked_list.h"

void test_create_list(int amount) {
    PriorityQueueList pq;
    auto start = std::chrono::system_clock::now();
    for (int i = 1; i <= amount; i++) {
        pq.push(i, i);
    }
    auto end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Czas tworzenia listy: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_push_list(PriorityQueueList& pq, int data, int priority) {
    auto start = std::chrono::high_resolution_clock ::now();
    pq.push(data, priority);
    auto end = std::chrono::high_resolution_clock ::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Czas dodawania elementu do listy: " << elapsed.count() << " s" << std::endl;
}

void test_extractMax_list(PriorityQueueList& pq){
    auto start = std::chrono::system_clock::now();
    pq.extractMax();
    auto end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Czas usuwania elementu z listy: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_peek_list(PriorityQueueList& pq){
    auto start = std::chrono::system_clock::now();
    pq.peek();
    auto end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Czas podgladania elementu z listy: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_modifyPriority_list(PriorityQueueList& pq, int data, int newPriority){
    auto start = std::chrono::system_clock::now();
    pq.modifyPriority(data, newPriority);
    auto end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Czas modyfikowania priorytetu elementu z listy: " << cpu_total_time_ns << " ns" << std::endl;
}

void test_getSize_list(PriorityQueueList& pq){
    auto start = std::chrono::system_clock::now();
    pq.getSize();
    auto end = std::chrono::system_clock::now();
    auto cpu_total_time_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Czas pobierania rozmiaru listy: " << cpu_total_time_ns << " ns" << std::endl;
}
