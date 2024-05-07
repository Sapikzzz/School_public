#include <iostream>
#include "priority_queue_linked_list.h"
#include "priority_queue_heap.h"
#include "list_tests.h"
#include "heap_tests.h"

int main() {
    PriorityQueueList pqList;
    PriorityQueueHeap pqHeap;

    for(int i= 0; i < 10000; i++) {  // Wypełnianie listy i kopca tą samą ilością elementów
        pqList.push(i, i); // Test dla dodawania elementow do listy
        pqHeap.push(i, i); // Test dla dodawania elementow do kopca
    }
    std::cout << "Testy dla pusha: " << std::endl; // Testy dla dodawania elementu do listy i kopca
//
    test_push_list(pqList, 1, 9999999); // Test dla dodawania elementu do listy
    test_push_heap(pqHeap, 1, 9999999); // Test dla dodawania elementu do kopca

//
    std::cout << "Testy dla extractMax: " << std::endl; // Testy dla usuwania elementu z listy i kopca

    test_extractMax_list(pqList); // Test dla usuwania elementu z listy
    test_extractMax_heap(pqHeap); // Test dla usuwania elementu z kopca


    std::cout << "Testy dla peek: " << std::endl; // Testy dla podgladania elementu z listy i kopca

    test_peek_list(pqList); // Test dla podgladania elementu z listy
    test_peek_heap(pqHeap); // Test dla podgladania elementu z kopca


    std::cout << "Testy dla modyfikowania priorytetu elementu z listy i kopca do gory: " << std::endl;

    test_modifyPriority_list(pqList, 160000000, 1000000000); // Test dla zmiany priorytetu elementu z listy
    test_modifyPriority_heap(pqHeap, 160000000, 1000000000); // Test dla zmiany priorytetu elementu z kopca

//
    std::cout << "Testy dla modyfikowania priorytetu elementu z listy i kopca w dol: " << std::endl;

    test_modifyPriority_list(pqList, 800000, 0); // Test dla zmiany priorytetu elementu z listy
    test_modifyPriority_heap(pqHeap, 800000, 0); // Test dla zmiany priorytetu elementu z kopca

    return 0;
}
