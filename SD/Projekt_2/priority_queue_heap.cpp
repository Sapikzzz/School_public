#include "priority_queue_heap.h"
#include <iostream>
#include <cmath>

//Inicjalizuje kolejkę priorytetową o początkowej pojemności 1 i rozmiarze 0.
PriorityQueueHeap::PriorityQueueHeap() : size(0), capacity(1) {
    heapArray = new HeapElement[capacity]; //tworzy dynamiczną tablicę heapArray o początkowej pojemności.
}


//Destruktor -usuwa dynamiczną tablicę heapArray, zwalniając przydzieloną pamięć, aby uniknąć wycieków pamięci.
PriorityQueueHeap::~PriorityQueueHeap() {
    delete[] heapArray;
}


//Tworzy większą tablicę, kopiuje istniejące elementy do nowej tablicy, a następnie usuwa starą tablicę i zastępuje ją nową.
void PriorityQueueHeap::resize(int newCapacity) {
    HeapElement* newArray = new HeapElement[newCapacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = heapArray[i];
    }
    delete[] heapArray;
    heapArray = newArray;
    capacity = newCapacity;
}


//Dodaje nowy element do kolejki priorytetowej.
void PriorityQueueHeap::push(int priority, int data) {
    if (size == capacity) {
        resize(capacity * 2); //Jeśli rozmiar osiągnie pojemność, tablica jest powiększana.
    }
    heapArray[size] = {priority, data}; //Nowy element jest dodawany na koniec tablicy.
    heapifyUp(size); //heapifyUp() przenosi nowy element w górę kopca, aby przywrócić własność kopca, gdzie niższy element ma niższy priorytet.
    size++;
}


//Usuwa i zwraca element z najwyższym priorytetem (korzeń kopca).
const int PriorityQueueHeap::extractMax() {
    if (size == 0) {
        std::cout<< "Kolejka jest pusta" <<std::endl;
        return 0;
    } else {
        int maxData = heapArray[0].data;
        heapArray[0] = heapArray[--size];
        heapifyDown(0);
        return maxData;
    }
}


//Zwraca element z najwyższym priorytetem bez usuwania go (korzeń kopca).
int PriorityQueueHeap::peek() const {
    if (size == 0) {
        std::cout<< "Kolejka jest pusta" <<std::endl;
        return 0;
    } else {
        return heapArray[0].data;
    }
}


//Zwraca liczbę elementów w kolejce.
int PriorityQueueHeap::getSize() const {
    return size;
}


//Zmienia priorytet istniejącego elementu.
void PriorityQueueHeap::modifyPriority(int data, int newPriority) {
    int i;
    for (i = 0; i < size; i++) {
        if (heapArray[i].data == data) {
            heapArray[i].priority = newPriority;
            break;
        }
    }
    if (i < size) {
        heapifyUp(i);
        heapifyDown(i);
    }
}


//Przenosi element w górę drzewa, aby przywrócić własność kopca po dodaniu nowego elementu lub zmianie priorytetu.
void PriorityQueueHeap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heapArray[index].priority > heapArray[parent].priority) {
        std::swap(heapArray[index], heapArray[parent]);
        heapifyUp(parent);
    }
}

//Przenosi element w dół kopca, aby przywrócić własność kopca po usunięciu elementu lub zmianie priorytetu.
void PriorityQueueHeap::heapifyDown(int index) {
    int left, right, largest;
    left = 2 * index + 1;
    right = 2 * index + 2;
    largest = index;
    if (left < size && heapArray[left].priority > heapArray[largest].priority) {
        largest = left;
    }
    if (right < size && heapArray[right].priority > heapArray[largest].priority) {
        largest = right;
    }
    if (largest != index) {
        std::swap(heapArray[index], heapArray[largest]);
        heapifyDown(largest);
    }
}

void PriorityQueueHeap::printAll() {
    for (int i = 0; i < size; i++) {
        std::cout << "'" << heapArray[i].data << "'   |   " << " Priorytet: " << heapArray[i].priority << std::endl;
    }
    std::cout << std::endl;
}

//Metody heapifyDown() i heapifyUp() zapewniają, że elementy w kopcu są zawsze odpowiednio uporządkowane,
// co jest kluczowe dla działania kolejki priorytetowej.
