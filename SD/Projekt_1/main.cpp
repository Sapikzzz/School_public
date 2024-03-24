#include <iostream>
#include <chrono>
#include "linked_list.h"
#include "test_linked_list.h"


int main() {
    test_creating(100000);
    test_creating(1000000);
    test_creating(10000000);

    LinkedList list;
    for (int i = 0; i < 1000000; i++) {
        list.add_last(i);
    }

    test_add_first(list);
    test_add_last(list);
    test_add_at(50000, list);

    test_remove_first(list);
    test_remove_last(list);
    test_remove_at(50000, list);

    test_check_if_present(900000, list);

    return 0;
}
//0.00000007 , 0,00000004