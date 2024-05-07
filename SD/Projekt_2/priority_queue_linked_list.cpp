//
// Created by Jakub on 29.03.2024.
//

#include <iostream>
#include "priority_queue_linked_list.h"

PriorityQueueList::PriorityQueueList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

PriorityQueueList::~PriorityQueueList() {
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

void PriorityQueueList::push(int data, unsigned int priority) {
    Node *newNode = new Node(data, priority);
    if (head == nullptr) {
        head = newNode; // ustawienie wskaznika head i tail na nowy element jako ze jest to jedyny element w liscie
        tail = newNode;
    } else {
        tail->next = newNode;   // ustawienie wskaznika next ostatniego elementu (tail) na nowy element
        tail = newNode;        // ustawienie nowego elementu jako ostatni element (tail)
    }
    size++;
}

int PriorityQueueList::extractMax() {
    if (size == 0) {
        std::cout << "Kolejka jest pusta" << std::endl;
        return 0;
    } else {
        Node *temp = head;
        Node *maxNode = head;
        unsigned int maxPriority = head->priority;
        int maxData = head->data;
        while (temp != nullptr) {
            if (temp->priority > maxPriority) {
                maxData = temp->data;
                maxPriority = temp->priority;
                maxNode = temp;
            }
            temp = temp->next;
        }
        delete maxNode;
        size--;
        return maxData;
    }
}

int PriorityQueueList::peek() {
    if(size == 0) {
        std::cout << "Kolejka jest pusta" << std::endl;
        return 0;
    } else {
        Node *temp = head;
        Node *maxNode = head;
        unsigned int maxPriority = head->priority;
        int maxData = head->data;
        while (temp != nullptr) {
            if (temp->priority > maxPriority) {
                maxData = temp->data;
                maxPriority = temp->priority;
                maxNode = temp;
            }
            temp = temp->next;
        }
        return maxData;
    }
}

bool PriorityQueueList::empty() {
    return size == 0;
}

void PriorityQueueList::printAll() {
    Node *current = head;
    while (current != nullptr) {
        std::cout << "'" << current->data << "'" << "   |   Priorytet: " << current->priority << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

int PriorityQueueList::getSize() {
    return size;
}

void PriorityQueueList::modifyPriority(int data, unsigned int newPriority) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == data) {
            temp->priority = newPriority;
            return;
        }
        temp = temp->next;
    }
}
