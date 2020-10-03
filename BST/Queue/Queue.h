#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H

#include "./../BST.h"

class Node{
    public:
        TreeNode* item;
        Node* next;
        Node(TreeNode* item);
};

class Queue{
    private:
        Node* first;
        Node* last;
        int l;
    public:
        Queue();
        void enqueue(TreeNode* item);
        TreeNode* dequeue();
        int length();
};

#endif