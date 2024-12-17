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

    void removeNode(int value) {
        Node *current = head;
        // Transverse the list
        while (current) {
            // checks if it is the value to be removed
            if (current->data == value) {
                if (current == head) {
                    //adjusts the head if it's the head
                    head = current->next;
                    if (head) {
                        head->previous = nullptr;
                    }
                }
                //adjusts the tail if its the tail
                else if (current == tail) {
                    tail = current->previous;
                    if (tail) {
                        tail->next = nullptr;
                    }
                }
                // adjusts the current if its in the middle
                else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                // Deletes the current node
                delete current;
                return;

            }
        }
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
    list.removeNode(1);
    list.printList();

    return 0;
}

