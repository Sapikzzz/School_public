//
// Created by Jakub on 24.03.2024.
//

#include <iostream>
#include <chrono>
#include "dynamic_array.h"

void test_creating_array(int amount){
    DynamicArray array;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < amount; i++){
        array.add_last(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Creating array of " << amount <<" size took: " << elapsed.count() << "s" << std::endl;
    array.remove_all();
}

void test_add_array_first(DynamicArray& array){
    auto start = std::chrono::high_resolution_clock::now();
    array.add_first(1000000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Adding element at beginning of array took: " << elapsed.count() << "s" << std::endl;
}

void test_add_array_last(DynamicArray& array){
    auto start = std::chrono::high_resolution_clock::now();
    array.add_last(1000000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Adding element at the end of the array took: " << elapsed.count() << "s" << std::endl;
}

void test_add_array_at(int index, DynamicArray& array){
    auto start = std::chrono::high_resolution_clock::now();
    array.add_at(index, 1000000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Adding element at " << index << " index took: " << elapsed.count() << "s" << std::endl;
}

void test_remove_array_first(DynamicArray& array){
    auto start = std::chrono::high_resolution_clock::now();
    array.remove_first();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Removing first element took: " << elapsed.count() << "s" << std::endl;
}

void test_remove_array_last(DynamicArray& array){
    auto start = std::chrono::high_resolution_clock::now();
    array.remove_last();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Removing last element took: " << elapsed.count() << "s" << std::endl;
}

void test_remove_array_at(int index, DynamicArray& array){
    auto start = std::chrono::high_resolution_clock::now();
    array.remove_at(index);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Removing element at " << index << " index took: " << elapsed.count() << "s" << std::endl;
}

void test_check_array_if_present(int data, DynamicArray& array){
    auto start = std::chrono::high_resolution_clock::now();
    array.check_if_present(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Checking if element is present took: " << elapsed.count() << "s" << std::endl;
}



