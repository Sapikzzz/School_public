//
// Created by Jakub on 29.03.2024.
//

#ifndef PROJEKT_1_PRIORITY_QUEUE_H
#define PROJEKT_1_PRIORITY_QUEUE_H

template <typename T>

class PriorityQueue {
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

    PriorityQueue() : head(nullptr), tail(nullptr), size(0) {}

    void push(const T &data, unsigned int priority);

    const T removeMin();

    bool empty();

    void printAll();

    ~PriorityQueue() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif //PROJEKT_1_PRIORITY_QUEUE_H
