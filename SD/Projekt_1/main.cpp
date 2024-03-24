#include <iostream>
#include <chrono>
#include "linked_list.h"
#include "test_linked_list.h"
#include "dynamic_array.h"
#include "test_dynamic_array.h"


int main() {
    std::cout << "Linked List tests:" << std::endl;
    std::cout << std::endl;
    test_creating_list(100000);
    test_creating_list(1000000);
    test_creating_list(10000000);

    LinkedList list;
    for (int i = 0; i < 1000000; i++) {
        list.add_last(i);
    }

    test_add_list_first(list);
    test_add_list_last(list);
    test_add_list_at(100000, list);

    test_remove_list_first(list);
    test_remove_list_last(list);
    test_remove_list_at(600000, list);

    test_check_list_if_present(900000, list);
    std::cout << std::endl;
    std::cout << "Dynamic Array tests:" << std::endl;
    std::cout << std::endl;
    test_creating_array(100000);
    test_creating_array(1000000);
    test_creating_array(10000000);

    DynamicArray array;
    for (int i = 0; i < 1000000; i++) {
        array.add_last(i);
    }

    test_add_array_first(array);
    test_add_array_last(array);
    test_add_array_at(100000, array);

    test_remove_array_first(array);
    test_remove_array_last(array);
    test_remove_array_at(600000, array);

    test_check_array_if_present(900000, array);

    return 0;
}