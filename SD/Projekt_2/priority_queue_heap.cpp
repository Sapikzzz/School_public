#include "priority_queue_heap.h"
#include <iostream>


//Inicjalizuje kolejkę priorytetową o początkowej pojemności 1 i rozmiarze 0.
PriorityQueueHeap::PriorityQueueHeap() : size(0), capacity(1) {
    heapArray = new HeapElement[capacity]; //worzy dynamiczną tablicę heapArray o początkowej pojemności.
}


//Destruktor -usuwa dynamiczną tablicę heapArray, zwalniając przydzieloną pamięć, aby uniknąć wycieków pamięci.
PriorityQueueHeap::~PriorityQueueHeap() {
    delete[] heapArray;
}


//Tworzy nową, większą tablicę, kopiuje istniejące elementy do nowej tablicy, a następnie usuwa starą tablicę i zastępuje ją nową.
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
void PriorityQueueHeap::insert(int priority, int data) {
    if (size == capacity) {
        resize(capacity * 2); //Jeśli rozmiar osiągnie pojemność, tablica jest powiększana.
    }
    heapArray[size] = {priority, data}; //Nowy element jest dodawany na koniec tablicy.
    heapifyUp(size); //heapifyUp() jest wywoływane, aby przywrócić własność kopca.
    size++;
}


//Usuwa i zwraca element z najwyższym priorytetem (korzeń kopca).
HeapElement PriorityQueueHeap::extractMax() {
    if (size == 0) {
        std::cout<<("Queue is empty!")<<std::endl;
        return HeapElement{-1, -1};
    } else {

        HeapElement max = heapArray[0];
        heapArray[0] = heapArray[--size];
        heapifyDown(0);
        return max;
    }
}


//Zwraca element z najwyższym priorytetem bez usuwania go (korzeń kopca).
HeapElement PriorityQueueHeap::peek() const {
    if (size == 0) {
        std::cout<<("Queue is empty!")<<std::endl;
        return HeapElement{-1, -1};
    } else {
        return heapArray[0];
    }
}


//Zwraca liczbę elementów w kolejce.
int PriorityQueueHeap::getSize() const {
    return size;
}


//Zmienia priorytet istniejącego elementu.
void PriorityQueueHeap::modifyKey(int data, int newPriority) {
    int i;
    for (i = 0; i < size; i++) {
        //Szuka elementu i zmienia jego priorytet
        if (heapArray[i].data == data) {
            heapArray[i].priority = newPriority;
            break;
        }
    }
    //Stosuje heapifyUp() oraz heapifyDown(), aby przywrócić własność kopca.
    if (i < size) {
        heapifyUp(i);
        heapifyDown(i);
    }
}


//Przenosi element w górę drzewa, aby przywrócić własność kopca po dodaniu nowego elementu lub zmianie priorytetu.
void PriorityQueueHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heapArray[index].priority > heapArray[parent].priority) {
            std::swap(heapArray[index], heapArray[parent]);
            index = parent;
        } else {
            break;
        }
    }
}


//Przenosi element w dół kopca, aby przywrócić własność kopca po usunięciu elementu lub zmianie priorytetu.
void PriorityQueueHeap::heapifyDown(int index) {
    int left, right, largest;
    while (true) {
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
            index = largest;
        } else {
            break;
        }
    }
}

void PriorityQueueHeap::printAll() {
    for (int i = 0; i < size; i++) {
        std::cout << heapArray[i] << std::endl;
    }
    std::cout << std::endl;
}

//Metody heapifyDown() i heapifyUp() zapewniają, że elementy w kopcu są zawsze odpowiednio uporządkowane,
// co jest kluczowe dla działania kolejki priorytetowej.