//
// Created by jack on 12/18/24.
//
#include <iostream>

#include "LinkedList.h"

int main() {
    LinkedList list;
    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    list.removeNode(1);
    list.printList();
    list.push();
    list.printList();

    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    list.pop();
    list.printList();

    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    std::cout << list.index_node(3) << std::endl;
    std:: cout << list.len();



    return 0;
}