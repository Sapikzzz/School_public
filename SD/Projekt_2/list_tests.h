//
// Created by Jakub on 03.05.2024.
//

#ifndef PROJEKT_2_LIST_TESTS_H
#define PROJEKT_2_LIST_TESTS_H

void test_create_list(int amount);
void test_push_list(PriorityQueueList& , int data, int priority);
void test_extractMax_list(PriorityQueueList& pq);
void test_peek_list(PriorityQueueList& pq);
void test_modifyPriority_list(PriorityQueueList& pq, int data, int newPriority);
void test_getSize_list(PriorityQueueList& pq);

#endif //PROJEKT_2_LIST_TESTS_H
