//
// Created by Jakub on 29.03.2024.
//

#include <iostream>
#include "priority_queue.h"

template <typename T>
void PriorityQueue<T>::push(const T &data, unsigned int priority) {
    Node *newNode = new Node(data, priority, nullptr);
    if (head == nullptr) {
        head = newNode; // ustawienie wskaznika head i tail na nowy element jako ze jest to jedyny element w liscie
        tail = newNode;
    } else {
            tail->next = newNode;   // ustawienie wskaznika next ostatniego elementu (tail) na nowy element
            tail = newNode;        // ustawienie nowego elementu jako ostatni element (tail)
    }
    size++;
}

template <typename T>
const T PriorityQueue<T>::removeMin() {
    Node *temp = head;
    Node *prev = nullptr;
    Node *minNode = head;
    Node *minPrev = nullptr;
    T minData = head->data;
    unsigned int minPriority = head->priority;
    // Przeszukujemy listę w poszukiwaniu elementu o najniższym priorytecie
    while (temp != nullptr) {
        if (temp->priority < minPriority) {
            minData = temp->data;
            minPriority = temp->priority;
            minNode = temp;
            minPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }
    // Usuwamy element o najniższym priorytecie
    if (minPrev == nullptr) {  // jeśli element o najniższym priorytecie jest głową
        head = minNode->next;
    } else {
        minPrev->next = minNode->next;
    }
    delete minNode;
    size--;
    return minData;
}


template <typename T>
bool PriorityQueue<T>::empty() {
    return size == 0;
}

template <typename T>
void PriorityQueue<T>::printAll() {
    Node *current = head;
    while (current != nullptr) {
        std::cout << "'" << current->data << "'" << "   |   Priorytet: " << current->priority << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

template class PriorityQueue<std::string>;