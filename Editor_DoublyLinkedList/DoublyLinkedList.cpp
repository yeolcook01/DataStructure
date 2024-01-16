#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() {  // Constructor.
    // For Part 2, You have to initialize `cursor`.
    head = nullptr;
    tail = nullptr;
    cursor = new Node;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList(){  //Destructor.
    //Ensure proper memory management to prevent leaks.
   delete cursor;
    if (List_size()>0){
        Node* crt = head;
        for (int i=0; i<List_size(); i++){
            Node* old = crt;
            crt = crt->next;
           delete old;
        }
    }
}

int DoublyLinkedList::List_size() { // Return the size of the list.
    return size;
}

bool DoublyLinkedList::Empty() { // Check if the list is empty (`true` for empty).
    if(size == 0) {return true;}
    else {return false;}
}

void DoublyLinkedList::Print() { // Print all the data in the list.
    if (Empty()) {
        std::cout << "Nothing to print." << std::endl;
    }
    else {
        Node* crt = head;
        const int iter = List_size();

        for (int i=0; i<iter; i++){
            std::cout << crt->data << " ";
            crt = crt->next;
        }
        std::cout << std::endl;
    }
}

void DoublyLinkedList::Append(int data) { // Insert the new node to the list.

    Node* newNode = new Node;
    newNode->data = data;

    if (Empty()) {
        head = newNode;
        head->prev = nullptr;
        head->next = nullptr;
        tail = newNode;
        tail->prev = nullptr;
        tail->next = nullptr;}
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = nullptr;}

    size++;
}

void DoublyLinkedList::Delete_idx(int idx) { // Delete the node with index `idx`.

    if (Empty()) {
        std::cout << "Nothing to delete." << std::endl;
        return;
    }

    else if (idx >= List_size() || idx < 0) {
        return;
    }

    else {
        if (idx==0){ //delete head
            Node* old = head;
            if (List_size()==1) { //if there is only one node
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }

            delete old;
        }
        else if (idx==List_size()-1){ //delete tail
            Node* old = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete old;
        }
        else {
            Node* crt = head;
            for (int i=0; i<idx; i++){ //find the node to delete
                crt = crt->next;
            }
            crt->prev->next = crt->next;
            crt->next->prev = crt->prev;
            delete crt;
        }

        size--;
    }
}

void DoublyLinkedList::Delete_data(int data) { // Delete all nodes with the data value of `data`.

    if (Empty()){
        std::cout << "Nothing to delete." << std::endl;
    }
    else {
        Node* crt = head;
        const int iter = List_size();

        for (int i=0; i<iter; i++) {
            if (crt->data == data) {
                Node* old = crt;

                if (old == head){
                    if (List_size() == 1){ //if there is only one node
                        head = nullptr;
                        tail = nullptr;
                    }
                    else {
                        head = head->next;
                        head->prev = nullptr;
                    }
                }
                else if (old == tail){
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else {
                    old->prev->next = old->next;
                    old->next->prev = old->prev;
                }
                crt = crt->next;
                delete old;
                size--;
            }
            else {
                crt = crt->next;
            }


        }
    }
}

void DoublyLinkedList::Reverse() { // Reverse ordering of the list.

    if (Empty()){
        std::cout << "Nothing to reverse." << std::endl;
        return;
    }

    else {
            Node* crt = head;
            const int iter = List_size();

            for (int i=0; i<iter; i++){
                Node* temp = crt->prev;
                crt->prev = crt->next;
                crt->next = temp;
                crt = crt->prev;
            }
            Node* temp = head;
            head = tail;
            tail = temp;
    }

    Set_cursor();
}

// Required to solve Part 2.
void DoublyLinkedList::Set_cursor() { //Set cursor at the tail

    cursor->prev = tail;
    cursor->next = nullptr;
}

void DoublyLinkedList::Left(){ // Move cursor one character to the left

    if (Empty() || (cursor->prev == nullptr)){
        return;
    }
    else {
        cursor->next = cursor->prev;
        cursor->prev = cursor->prev->prev;
    }
}

void DoublyLinkedList::Right(){ // Move cursor one character to the right

    if (Empty() || (cursor->next == nullptr)){
        return;
    }
    else {
        cursor->prev = cursor->next;
        cursor->next = cursor->next->next;
    }
}

void DoublyLinkedList::Backspace(){ // Delete node left of the cursor

    if (Empty() || (cursor->prev == nullptr)){
        return;
    }
    else {
        Node* old = cursor->prev;

        if (old == head) { //if the node to delete is the head
            if (List_size() == 1){ //if there is only one node
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
            cursor->prev = nullptr;

        }

        else if (old == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            cursor->prev = tail;
        }
        else {
            old->prev->next = old->next;
            old->next->prev = old->prev;
            cursor->prev = old-> prev;
        }

        delete old;
        size--;
    }
}


void DoublyLinkedList::Insert(int data) { // Insert a new node with the value 'data' to left-side of 'cursor.'

    Node* newNode = new Node;
    newNode->data = data;

    if (Empty()){ //if the array was empty
        head = newNode;
        head->prev = nullptr;
        head->next = nullptr;
        tail = newNode;
        tail->prev = nullptr;
        tail->next = nullptr;

        cursor->prev = tail;
        cursor->next = nullptr;}

    else if (cursor->prev == nullptr){ //if the cursor is before the head
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        head->prev = nullptr;

        cursor->prev = head;
    }

    else if (cursor->next == nullptr){ //if the cursor is after the tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = nullptr;

        cursor->prev = tail;
    }

    else { //if the cursor is between two nodes
        newNode->prev = cursor->prev;
        newNode->next = cursor->next;
        cursor->prev->next = newNode;
        cursor->next->prev = newNode;

        cursor->prev = newNode;
    }

    size++;
}

void DoublyLinkedList::Find_and_replace(int from, int to){ // Find 'from' in the list and replace it to 'to.'

    if (Empty()){
        return;
    }
    else {
        Node* crt = head;
        const int iter = List_size();

        for (int i=0; i<iter; i++) {
            if (crt->data == from) {
                crt->data = to;
            }

            crt = crt->next;
        }
    }

}

