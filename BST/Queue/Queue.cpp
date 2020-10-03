#include "Queue.h"

Node::Node(TreeNode* item) : item(item){
    next = nullptr;
}

Queue::Queue(){
    first = nullptr;
    last = nullptr;
    l = 0;
}

void Queue::enqueue(TreeNode* item){
    Node* newNode = new Node(item);
    if(!first){
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    l++;
}

TreeNode* Queue::dequeue(){
    if(!first){
        return nullptr;
    } else {
        TreeNode* removedValue = first->item;
        first = first->next;
        l--;
        return removedValue;
    }
}

int Queue::length(){
    return this->l;
}