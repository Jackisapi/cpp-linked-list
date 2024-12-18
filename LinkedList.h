#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// The LinkedList class defines a doubly-linked list
class LinkedList {
public:
    // Constructor
    LinkedList();

    // Adds a new node to the end of the list
    void append(int value);

    // Prints all nodes in the list
    void printList();

    // Finds the index of a node with the specified value
    int index_node(int value);

    // Removes a node with the specified value
    void removeNode(int value);

    // Returns the length of the list
    int len();

    // Deletes all nodes starting from the head
    void push();

    // Deletes all nodes starting from the tail
    void pop();

    // A simple bubble sort (INDEV)
    void sort();

private:
    // Defines the "box"/node
    struct Node {
        int data;          // What the box contains
        Node* next;        // Pointer to the next box
        Node* previous;    // Pointer to the previous box
    };

    Node* head;  // Front of the list
    Node* tail;  // End of the list
};

#endif // LINKEDLIST_H
