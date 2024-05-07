#ifndef PROJEKT_2_PRIORITY_QUEUE_HEAP_H
#define PROJEKT_2_PRIORITY_QUEUE_HEAP_H
#include <iostream>

struct HeapElement {
    int priority;
    int data;
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

    void push(int priority, int data);

    const int extractMax();

    int peek() const;

    int getSize() const;

    void modifyPriority(int data, int newPriority);

    void printAll();
};

#endif // PROJEKT_2_PRIORITY_QUEUE_HEAP_H