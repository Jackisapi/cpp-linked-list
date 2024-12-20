#include "LinkedList.h"
#include <iostream>


// Constructor
LinkedList::LinkedList() {
    // Start of List (front of train)
    head = nullptr;
    // End of List (back of train)
    tail = nullptr;
}

// Appends a new node to the end of the list
void LinkedList::append(int value) {
    // Creates the "box"/node for value to be in
    Node *temp = new Node;

    // Puts value in the box
    temp->data = value;
    temp->next = nullptr;
    temp->previous = tail;

    // Checks if the train has no cars/nodes
    if (head == nullptr) {
        head = temp;
        tail = temp;
    }
    // Adds more cars/nodes to the train
    else {
        tail->next = temp;
        tail = temp;
    }
}

// Prints the list from head to tail
void LinkedList::printList() {
    // Fetches the front-facing car
    // Until it reaches the end, print each box
    // Checks to see if the list is empty to prevent SEGFAULT
    if (LinkedList::len() != 0){
        Node *current = head;
        std::cout << "[";
        for (int i = 1; i <= LinkedList::len() -1 ; i++) {
            std::cout << current->data;
            std::cout << " -> ";
            current = current->next;
        }
        std::cout << current->data;
        std::cout << "]" << std::endl;
    }else {
        // If empty print a empty list
        std::cout << "[ ]"<< std::endl;
    }
}

// Finds the index of a node with the specified value
int LinkedList::fetch_node(int value) {
    // Starts at the head
    Node *current = head;
    int index = 0;
    // Traverse the list
    while (current != nullptr) {
        // Checks if the current position matches the value
        if (current->data == value) {
            return index;  // Returns the index if found
        }
        current = current->next;
        index++;
    }
    return -1;  // Returns -1 if the value is not found
}

// Removes a node with the specified value
void LinkedList::removeNode(int value) {
    Node *current = head;
    // Traverse the list
    while (current != nullptr) {
        // Checks if it is the value to be removed
        if (current->data == value) {
            if (current == head) {
                // Adjusts the head if it's the head
                head = current->next;
                if (head) {
                    head->previous = nullptr;
                }
            }
            // Adjusts the tail if it's the tail
            else if (current == tail) {
                tail = current->previous;
                if (tail) {
                    tail->next = nullptr;
                }
            }
            // Adjusts the current if it's in the middle
            else {
                current->previous->next = current->next;
                current->next->previous = current->previous;
            }
            // Deletes the current node
            delete current;
            return;
        }
        current = current->next;  // Continue traversing
    }
}


// Returns the length of the list
int LinkedList::len() {
    Node *current = head;
    int length = 0;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}


// Deletes node that is currently at the head (front of train)
void LinkedList::push() {
    Node *current = head;
    head = current->next;
    delete current;
}

// Deletes node that is currently at the tail (back of the train)
void LinkedList::pop() {
    if (tail == nullptr) {
        // checks if the list is empty
    }else {
        Node *current = tail;
        tail = current->previous;

    }

    Node *current = tail;
    // goes to current tail
    tail = current->previous; // moves tail down

    if (tail != nullptr) {
        tail->next = nullptr; // Ensure the new tail has no next node

    } else {
        // If the list becomes empty, set head to nullptr as well
        head = nullptr;
    }

    delete current; // Delete the old tail node
}


void LinkedList::sort() {
    // for each item in the list
    for (int i = 1; i < len(); i++) {
        Node *current = head;
        // for each item in the list two electric boogaloo
        for (int j = 0; j < len() - i; j++) {
            // checks to see if the data currently selected is bigger than the next node
            if (current->data > current->next->data){
                // if it is they swap
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            current = current->next;
            }
        }
    }
}

int LinkedList::index_node(int pos) {
    Node *current = head;
    // moves pointer to the position required
    for (int i = 0; i != pos; i++) {
        current = current->next;
    }
    //returns the data at that positon
    return current->data;
}