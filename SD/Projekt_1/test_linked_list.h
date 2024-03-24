//
// Created by Jakub on 24.03.2024.
//

#ifndef PROJEKT_1_TEST_LINKED_LIST_H
#define PROJEKT_1_TEST_LINKED_LIST_H

// Test dla dodawania roznych ilosci elementow do listy
void test_creating_list(int amount);
void test_add_list_first(LinkedList& list);
void test_add_list_last(LinkedList& list);
void test_add_list_at(int index, LinkedList& list);

// Test dla usuwania elementow z listy
void test_remove_list_first(LinkedList& list);
void test_remove_list_last(LinkedList& list);
void test_remove_list_at(int index, LinkedList& list);

// Test dla sprawdzenia czy element jest w liscie
void test_check_list_if_present(int data, LinkedList& list);

#endif //PROJEKT_1_TEST_LINKED_LIST_H
