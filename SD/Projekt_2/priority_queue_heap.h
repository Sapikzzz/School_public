//
// Created by natal on 19.04.2024.
//
#ifndef PROJEKT_2_PRIORITY_QUEUE_HEAP_H
#define PROJEKT_2_PRIORITY_QUEUE_HEAP_H
#include <iostream>

struct HeapElement {
    int priority;
    int data;

    //Przeciazenie operatora
    friend std::ostream& operator<<(std::ostream& os, const HeapElement& element) {
        os << "Priorytet: " << element.priority << ", Dane: " << element.data;
        return os;
    }
};

class PriorityQueueHeap {
private:
    HeapElement* heapArray;
    int capacity;
    int size;
    void heapifyDown(int index);
    void heapifyUp(int index);
    void resize(int newCapacity);
public:
    PriorityQueueHeap();
    ~PriorityQueueHeap();
    void insert(int priority, int data);
    HeapElement extractMax();
    HeapElement peek() const;
    int getSize() const;
    void modifyKey(int data, int newPriority);
    void printAll();
};

#endif // PROJEKT_2_PRIORITY_QUEUE_HEAP_H