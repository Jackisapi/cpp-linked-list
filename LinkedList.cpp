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
    Node *current = head;
    // Until it reaches the end, print each box
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

// Finds the index of a node with the specified value
int LinkedList::index_node(int value) {
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

// Deletes all nodes starting from the head (front of the train)
void LinkedList::push() {
    Node *current = head;
    while (current != nullptr) {
        // Stores the next car
        Node *nextNode = current->next;
        // Removes the current car
        delete current;
        // Moves to the next car
        current = nextNode;
    }
    // After deletion, set the head and tail to nullptr
    head = nullptr;
    tail = nullptr;
}

// Deletes all nodes starting from the tail (back of the train)
void LinkedList::pop() {
    Node *current = tail;
    while (current != nullptr) {
        // Stores the previous car
        Node *prevNode = current->previous;
        // Removes the current car
        delete current;
        // Moves to the previous car
        current = prevNode;
    }
    // After deletion, set the head and tail to nullptr
    head = nullptr;
    tail = nullptr;
}

void LinkedList::sort() {
    for (int i = 1; i < len(); i++) {
        Node *current = head;
        for (int j = 0; j < len() - i; j++) {
            if (current->data > current->next->data){
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            current = current->next;
            }

        }
    }
}