//
// Created by Jakub on 24.03.2024.
//

#include <iostream>
#include <chrono>
#include "linked_list.h"

void test_creating(int amount){
    LinkedList list;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < amount; i++){
        list.add_last(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Creating list of " << amount <<" size took: " << elapsed.count() << "s" << std::endl;
    list.remove_all();
}

void test_add_first(LinkedList& list){
    auto start = std::chrono::high_resolution_clock::now();
    list.add_first(1000000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Adding element at beginning of list took: " << elapsed.count() << "s" << std::endl;
}

void test_add_last(LinkedList& list){
    auto start = std::chrono::high_resolution_clock::now();
    list.add_last(1000000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Adding element at the end of the list took: " << elapsed.count() << "s" << std::endl;
}

void test_add_at(int index, LinkedList& list){
    auto start = std::chrono::high_resolution_clock::now();
    list.add_at(index, 1000000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Adding element at " << index << " index took: " << elapsed.count() << "s" << std::endl;
}

void test_remove_first(LinkedList& list){
    auto start = std::chrono::high_resolution_clock::now();
    list.remove_first();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Removing first element took: " << elapsed.count() << "s" << std::endl;
}

void test_remove_last(LinkedList& list){
    auto start = std::chrono::high_resolution_clock::now();
    list.remove_last();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Removing last element took: " << elapsed.count() << "s" << std::endl;
}

void test_remove_at(int index, LinkedList& list){
    auto start = std::chrono::high_resolution_clock::now();
    list.remove_at(index);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Removing element at " << index << " index took: " << elapsed.count() << "s" << std::endl;
}

void test_check_if_present(int data, LinkedList& list){
    auto start = std::chrono::high_resolution_clock::now();
    list.check_if_present(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Checking if element is present took: " << elapsed.count() << "s" << std::endl;
}
