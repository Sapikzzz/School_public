//
// Created by Jakub on 24.03.2024.
//

#ifndef PROJEKT_1_TEST_DYNAMIC_ARRAY_H
#define PROJEKT_1_TEST_DYNAMIC_ARRAY_H

#include "dynamic_array.h"

// Test dla dodawania roznych ilosci elementow do listy
void test_creating_array(int amount);
void test_add_array_first(DynamicArray& array);
void test_add_array_last(DynamicArray& array);
void test_add_array_at(int index, DynamicArray& array);

// Test dla usuwania elementow z listy
void test_remove_array_first(DynamicArray& array);
void test_remove_array_last(DynamicArray& array);
void test_remove_array_at(int index, DynamicArray& array);

// Test dla sprawdzenia czy element jest w liscie
void test_check_array_if_present(int data, DynamicArray& array);

#endif //PROJEKT_1_TEST_DYNAMIC_ARRAY_H
