//
// Created by Jakub on 23.04.2024.
//

#ifndef PROJEKT_2_PRIORITY_QUEUE_LINKED_LIST_H
#define PROJEKT_2_PRIORITY_QUEUE_LINKED_LIST_H

struct Node {
    int data;
    unsigned int priority;
    Node *next;

    Node(int data, unsigned int priority){
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};

class PriorityQueueList {
    Node *head;
    Node *tail;
    unsigned int size;

public:

    PriorityQueueList();
    ~PriorityQueueList();

    void push(int data, unsigned int priority);

    int extractMax();

    bool empty();

    void printAll();

    int getSize();

    void modifyPriority(int data, unsigned int newPriority);

    int peek();
};

#endif //PROJEKT_2_PRIORITY_QUEUE_LINKED_LIST_H
