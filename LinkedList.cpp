//
// Created by jack on 11/2/24.
//
#include <iostream>

class LinkedList {
public:
    LinkedList()
    {
        //Start of List (front of train)
        head = nullptr;
        //End of List (back of train)
        tail = nullptr;
    }


    void append(int value)
    {
        //Creates the "box"/node for value to be in

        Node *temp = new Node;

        //puts val in the box
        temp->data = value;
        temp->next = nullptr;
        temp->previous = tail;

        // Checks if the train has no cars/nodes
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        //adds more cars/nodes  to the train
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }


    void printList() {
        //Fetches the front facing car
        Node *current = head;
        // until it reaches the end print each box
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }


    int index_node(int value) {
        //Starts at the head
        Node *current = head;
        //While not at the tail
        while (current != nullptr) {
            //checks if the current position is the value
            if (current->data == value) {
                //returns if found
                return true;
            }
            if (current->next == nullptr) {
                // if not found prints error
                return false;
            }
            current = current -> next;
        }
    }


    int len() {
        Node *current = head;
        int length = 0;
        while (current != nullptr) {
            length++;
            current = current -> next;
        }
        return length;
    }


    void push() {
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;  // store the next node
            delete current;                  // delete the current node
            current = nextNode;              // move to the next node
        }
        head = nullptr;  // after deletion, set head to nullptr to avoid dangling pointers
        tail = nullptr;  // also set tail to nullptr, as the list is now empty
    }



    void pop() {
        Node*current  = tail;
        while (current != nullptr) {
            Node *nextNode = current->previous;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }


    void remove(int position) {
        if (position < 1 || head == nullptr) {
            std::cout << "ERROR: POSITION DOES NOT EXIST" << std::endl;
            return;
        }

        Node *current = head;
        for (int i = 1; current != nullptr && i < position; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "ERROR: POSITION DOES NOT EXIST" << std::endl;
            return;
        }

        // Update the pointers of the adjacent nodes
        if (current->previous != nullptr) {
            current->previous->next = current->next;
        } else {
            head = current->next; // Update head if deleting the first node
        }

        if (current->next != nullptr) {
            current->next->previous = current->previous;
        } else {
            tail = current->previous; // Update tail if deleting the last node
        }

        delete current;
    }

        private:
        //Defines the "box"/node
        struct Node {
            //What the box contains
            int data;
            //Where it is positioned
            Node* next;
            Node* previous;
        };
        // Creates the front and back boxes
        Node *head;
        Node *tail;
    };

int main() {
    LinkedList list;
    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    list.printList();

    list.push();

    list.remove(0);
    list.remove(4);
    list.remove(9);
    list.printList();


    return 0;
}

