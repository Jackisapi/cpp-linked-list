//
// Created by jack on 12/18/24.
//
#include "LinkedList.h"

int main() {
    LinkedList list;
    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    list.removeNode(1);
    list.printList();

    return 0;
}