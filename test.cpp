//
// Created by jack on 12/18/24.
//
#include <iostream>

#include "LinkedList.h"

int main() {
    LinkedList list;
    for (int i = 10; i >= 1; i--) {
        list.append(i);
    }
    list.printList();
    list.sort();
    list.printList();
    list.push();
    list.pop();
    list.printList();
    std::cout << list.fetch_node(4) << std::endl;
    std::cout << list.index_node(4) << std::endl;
    return 0;
}