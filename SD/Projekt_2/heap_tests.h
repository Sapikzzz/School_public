//
// Created by Jakub on 03.05.2024.
//

#ifndef PROJEKT_2_HEAP_TESTS_H
#define PROJEKT_2_HEAP_TESTS_H

#include "priority_queue_heap.h"

void test_create_heap(int amount);
void test_push_heap(PriorityQueueHeap& pqh, int data, int priority);
void test_extractMax_heap(PriorityQueueHeap& pqh);
void test_peek_heap(PriorityQueueHeap& pqh);
void test_modifyPriority_heap(PriorityQueueHeap& pqh, int data, int newPriority);
void test_getSize_heap(PriorityQueueHeap& pqh);

#endif //PROJEKT_2_HEAP_TESTS_H
