//
// Created by Jakub on 24.03.2024.
//

#ifndef PROJEKT_1_DYNAMIC_ARRAY_H
#define PROJEKT_1_DYNAMIC_ARRAY_H


struct DynamicArray {
    int* array; // Wskaznik na tablice
    int size;   // Wielkosc tablicy
    int capacity;   // Pojemnosc tablicy

public:
    DynamicArray(); // Konstruktor dla dynamicznej tablicy
    ~DynamicArray();    // Destruktor dla dynamicznej tablicy

    void add_first(int data); // Dodawanie elementu na początku tablicy
    void add_last(int data);  // Dodawanie elementu na końcu tablicy
    void add_at(int index, int data);   // Dodawanie elementu na dowolnej pozycji tablicy
    void remove_first();  // Usuwanie pierwszego elementu z tablicy
    void remove_last();   // Usuwanie ostatniego elementu z tablicy
    void remove_at(int index);  // Usuwanie elementu z dowolnej pozycji tablicy

    void print_all();   // Wypisanie wszystkich elementów tablicy
    int get_size();   // Wypisanie rozmiaru tablicy

    void check_if_present(int data);    // Sprawdzenie czy element jest w tablicy

    void remove_all();  // Usunięcie wszystkich elementów z tablicy
};

#endif //PROJEKT_1_DYNAMIC_ARRAY_H
