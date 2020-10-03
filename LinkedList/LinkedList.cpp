#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    int length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::push(int value){
    if(head == nullptr){
        head = new Node(value);
        tail = head;
    } else {
        tail->next = new Node(value);
        tail->next->prev = tail;
        tail = tail->next;
    }
    length += 1;
}

void LinkedList::pop(int value){
    if(head == nullptr){
        head = new Node(value);
        tail = head;
    } else {
        Node *newNode = new Node(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length += 1;
}

void LinkedList::printList(){
    Node *current = head;
    while(current != nullptr){
        std::cout << current->value << std::endl;
        current = current->next;
    }
}

void LinkedList::printReversed(){
    Node *current = tail;
    while(current != nullptr){
        std::cout << current->value << std::endl;
        current = current->prev;
    }
}

void LinkedList::reverseList(){
    //Swap Head and Tail
    Node *current = head;
    head = tail;
    tail = current;

    //Temp Pointers to Keep Track of Prev/Next
    Node *next = nullptr;

    while(current != nullptr){
        //Swapping 
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        //Advancing
        current = next;
    }
}