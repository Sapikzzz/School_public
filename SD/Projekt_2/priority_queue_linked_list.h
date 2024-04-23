//
// Created by Jakub on 23.04.2024.
//

#ifndef PROJEKT_2_PRIORITY_QUEUE_LINKED_LIST_H
#define PROJEKT_2_PRIORITY_QUEUE_LINKED_LIST_H

template <typename T>

class PriorityQueueList {
    struct Node {
        T data;
        unsigned int priority;
        Node *next;

        Node(const T &data, unsigned int priority, Node *next) : data(data), priority(priority), next(next){}
    };

    Node *head; // wskaznik na poczatek kolejki
    Node *tail; // wskaznik na koniec kolejki
    unsigned int size;

public:

    PriorityQueueList() : head(nullptr), tail(nullptr), size(0) {}

    void push(const T &data, unsigned int priority);

    const T removeMin();

    bool empty();

    void printAll();

    int getSize();

    void modifyPriority(const T &data, unsigned int newPriority);

    T peek();

    ~PriorityQueueList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};


#endif //PROJEKT_2_PRIORITY_QUEUE_LINKED_LIST_H
