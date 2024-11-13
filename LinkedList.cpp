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


    // Chatgippity made this Imma just comment it (i got stuck for like a week)
    int removeNode(int position) {
        // checks if a position is there
        if (position < 1 || position > len()) {
            std::cerr << "Position out of range" << std::endl;
            return -1;
        }

        // checks to see if you are trying to remove the head
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {  // moves the current head
                head->previous = nullptr; //set the previous head as nullptr
            } else {
                tail = nullptr;  // if the list is deleted set tail to nullprt
            }
            int data = temp->data;
            delete temp;
            return data;
        }

        // Traverse to the node before the one to be removed
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }

        // Target node to delete
        Node* toDelete = current->next;
        int data = toDelete->data;

        // Adjust pointers
        current->next = toDelete->next;
        if (toDelete->next != nullptr) {
            toDelete->next->previous = current;
        } else {
            tail = current;  // Update tail if last node is removed
        }

        delete toDelete;
        return data;
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

