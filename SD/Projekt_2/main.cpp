#include <iostream>
#include "priority_queue_linked_list.h"
#include "priority_queue_heap.h"

int main() {
    PriorityQueueList<int> pq;
    pq.push(1, 1);
    pq.push(2, 1);
    pq.push(3, 3);
    pq.push(4, 4);
    pq.push(5, 5);
    pq.push(6, 6);
    pq.push(7, 7);
    pq.push(8, 8);
    pq.push(9, 9);
    pq.push(10, 10);

    pq.printAll();

    std::cout << "Usuwamy element o najniższym priorytecie: " << pq.removeMin() << std::endl;


    PriorityQueueHeap pqh;
    pqh.insert(1, 1);
    pqh.insert(2, 2);
    pqh.insert(3, 3);
    pqh.insert(4, 4);
    pqh.insert(5, 5);
    pqh.insert(6, 6);
    pqh.insert(7, 7);
    pqh.insert(8, 8);
    pqh.insert(9, 9);
    pqh.insert(10, 10);

    pqh.printAll();

    pqh.extractMax();

    pqh.printAll();

    return 0;
}
