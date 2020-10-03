#ifndef LINKEDLIST_CLASS_H
#define LINKEDLIST_CLASS_H

#include "Node.h"

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList();
        void push(int value);
        void pop(int value);
        void printList();
        void printReversed();
        void reverseList();
};

#endif