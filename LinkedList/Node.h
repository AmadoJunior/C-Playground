#ifndef NODE_CLASS_H
#define NODE_CLASS_H

class Node{
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int value);
};

#endif 