//
// Created by Jakub on 24.03.2024.
//

#include "iostream"
#include "linked_list.h"

LinkedList::LinkedList() {  // Konstruktor dla listy
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {     // Destruktor dla listy
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::add_last(int data) {
    Node* new_node = new Node(data);    //  Tworzenie nowego node z podanymi danymi

    //  Sprawdzenie czy lista jest pusta, jesli tak to ustawiamy nowy node jako head i tail
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } //  Jesli nie to ustawiamy nowy node jako nastepny dla taila i przesuwamy tail na nowy node
    else {
        tail->next = new_node;
        tail = new_node;
    }

    size++;
}

void LinkedList::add_first(int data) {
    Node* new_node = new Node(data);

    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } //    Jesli lista nie jest pusta to ustawiamy nowy node jako head i
    // ustawiamy nastepny node jako head
    else {
        new_node->next = head;
        head = new_node;
    }

    size++;
}

void LinkedList::add_at(int index, int data) {
    if (index < 0 || index > size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }

    if (index == 0) {
        add_first(data);
        return;
    }
    //  Jesli index jest rowny rozmiarowi listy to dodajemy element na koniec listy
    //  poprzez wywolanie funkcji add_last, co jest bardziej optymalne
    if (index == size) {
        add_last(data);
        return;
    }

    Node* new_node = new Node(data);
    Node* current = head;
    //  Przechodzimy do elementu przed elementem, ktory chcemy dodac za pomoca petli
    //  co daje nam zlozonosc czasowa O(n)
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    size++;
}

void LinkedList::remove_last() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    //  Jesli head i tail sa rowne to usuwamy head i tail, poniewaz lista ma jeden element
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    else {
        Node* current = head;
        //  Jesli nie to przechodzimy do elementu przed tail i usuwamy tail
        while (current->next != tail) {
            current = current->next;
        }
        // Usuwamy tail i ustawiamy nowy tail jako element przed tail
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    size--;
}

void LinkedList::remove_first() {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* current = head;
        head = head->next;
        delete current;
    }

    size--;
}

void LinkedList::remove_at(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    // Podobnie jak wczesniej bardziej optymalne jest dodawanie oraz usuwanie elementow za pomoca
    // funkcji add_first oraz add_last
    if (index == 0) {
        remove_first();
        return;
    }

    if (index == size - 1) {
        remove_last();
        return;
    }

    Node* current = head;

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node* to_delete = current->next;
    current->next = to_delete->next;
    delete to_delete;

    size--;
}

// Wypisanie wszystkich elementow listy przechodzac przez wszystkie elementy listy i
// wypisujac ich wartosci po kolei
void LinkedList::print_all() {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int LinkedList::print_size() {
    return size;
}

void LinkedList::check_if_present(int data) {
    Node* current = head;
    int index_present = 0;

    while (current != nullptr) {
        index_present++;
        if (current->data == data) {
            std::cout << "Element is present at " << index_present << " index" << std::endl;
            return;
        }

        current = current->next;
    }

    std::cout << "Element is not present" << std::endl;
}

void LinkedList::remove_all() {
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

