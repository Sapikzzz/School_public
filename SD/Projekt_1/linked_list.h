//
// Created by Jakub on 24.03.2024.
//

#ifndef PROJEKT_1_LINKED_LIST_H
#define PROJEKT_1_LINKED_LIST_H

struct Node {
    int data;   // Dane przechowywane w nodzie
    Node* next; // Wskaznik na nastepny nodzie

    Node(int data) {    // Konstruktor
        this->data = data;  // Przypisanie wartosci do pola data
        this->next = nullptr;   // Ustawienie wskaznika nastepnego node na nullptr
    }
};

class LinkedList {

    Node* head; // Wskaznik na pierwszy node
    Node* tail; // Wskaznik na ostatni node
    int size;   // Rozmiar listy

public:
    LinkedList();   // Konstruktor dla listy
    ~LinkedList();  // Destruktor dla listy

    void add_last(int data);    // Dodanie elementu na koniec listy
    void add_first(int data);   // Dodanie elementu na poczatek listy
    void add_at(int index, int data);   // Dodanie elementu na dowolna pozycje listy

    void remove_last();     // Usuniecie ostatniego elementu z listy
    void remove_first();    // Usuniecie pierwszego elementu z listy
    void remove_at(int index);  // Usuniecie elementu z dowolnej pozycji listy

    void print_all();   // Wypisanie wszystkich elementow listy
    int print_size();  // Wypisanie rozmiaru listy

    void check_if_present(int data);    // Sprawdzenie czy element jest w liscie

    void remove_all();  // Usuniecie wszystkich elementow z listy dla potrzeby testow

};


#endif //PROJEKT_1_LINKED_LIST_H
