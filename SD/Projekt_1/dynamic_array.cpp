//
// Created by Jakub on 24.03.2024.
//

#include <iostream>
#include "dynamic_array.h"


DynamicArray::DynamicArray() {
    this->size = 0; // Aktualny rozmiar tablicy
    this->capacity = 1; // Pojemnosc tablicy, domyslnie 1 dla jednego elementu
    this->array = new int[this->capacity];  // Tworzenie tablicy o pojemnosci
}

DynamicArray::~DynamicArray() {
    delete[] this->array;   // Usuniecie tablicy
}

void DynamicArray::add_first(int data) {
    if (this->size == this->capacity) { // Sprawdzenie czy tablica jest pelna
        this->capacity *= 2;        // Podwojenie pojemnosci tablicy
        int* new_array = new int[this->capacity];   // Stworzenie nowej tablicy o podwojonej pojemnosci
        for (int i = 0; i < this->size; i++) {  // Przepisanie elementow z poprzedniej tablicy do nowej
            new_array[i + 1] = this->array[i];  // Z przesunięciem o 1, dla zrobienia miejsca na nowy element
        }
        delete[] this->array;   // Usuniecie starej tablicy
        this->array = new_array;    // Przypisanie nowej tablicy jako aktualnej
    } else {    // Jesli tablica nie jest pelna
        for (int i = this->size; i > 0; i--) {  // Przesuniecie wszystkich elementow o 1, zaczynajac petle od konca
            this->array[i] = this->array[i - 1];    // Rozmiar tablicy bedzie zawsze wiekszy o 1 od najwiekszego inedksu
        }
    }
    this->array[0] = data;  // Dodanie elementu na poczatek tablicy
    this->size++;   // Zwiekszenie rozmiaru tablicy
}

void DynamicArray::add_last(int data) {
    if (this->size == this->capacity) { // Takie same kroki jak w add_first
        this->capacity *= 2;
        int* new_array = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
    }
    this->array[this->size] = data; // Dodanie elementu na koniec tablicy jeżeli nie jest pelna
    this->size++;
}

void DynamicArray::add_at(int index, int data) {
    if (index < 0 || index > this->size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (this->size == this->capacity) {
        this->capacity *= 2;
        int* new_array = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
    }
    for (int i = this->size; i > index; i--) {  // Przesunięcie tablicy o 1 od podanego indeksu do końca tablicy
        this->array[i] = this->array[i - 1];
    }
    this->array[index] = data;
    this->size++;
}

void DynamicArray::remove_first() {
    if (this->size == 0) {
        std::cout << "Array is empty" << std::endl;
        return;
    }
    for (int i = 0; i < this->size - 1; i++) {  // Przesunięcie tablicy o 1, usuwając pierwszy element
        this->array[i] = this->array[i + 1];
    }
    this->size--;
    if (this->size < this->capacity / 2) {  // Jeżeli rozmiar tablicy jest mniejszy niż połowa pojemności
        this->capacity /= 2;                // Zmniejszenie pojemności tablicy o połowę, aby nie marnować pamięci
        int* new_array = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
    }
}

void DynamicArray::remove_last() {
    if (this->size == 0) {
        std::cout << "Array is empty" << std::endl;
        return;
    }
    this->size--;   // Wystarczy zmniejszyć rozmiar tablicy o 1, aby usunąć ostatni element
    if (this->size < this->capacity / 2) {
        this->capacity /= 2;
        int* new_array = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
    }
}

void DynamicArray::remove_at(int index) {
    if (index < 0 || index >= this->size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    for (int i = index; i < this->size - 1; i++) {
        this->array[i] = this->array[i + 1];    // Przesunięcie tablicy o 1 w lewo od podanego indeksu do końca tablicy
    }
    this->size--;
    if (this->size < this->capacity / 2) {
        this->capacity /= 2;
        int* new_array = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
    }
}

void DynamicArray::print_all() {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->array[i] << " ";
    }
    std::cout << std::endl;
}

int DynamicArray::get_size() {
    return this->size;
}

void DynamicArray::check_if_present(int data) { // Przejście przez tablicę do elementu równego podanemu
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] == data) {
            std::cout << "Element is present at " << i << " index" <<  std::endl;
            return;
        }
    }
    std::cout << "Element is not present" << std::endl;
}

void DynamicArray::remove_all() {
    delete[] this->array;
    this->size = 0;
    this->capacity = 1;
    this->array = new int[this->capacity];
}

