#include "Node.h"

Node::Node(int value) : value(value) {
    this->next = nullptr;
    this->prev = nullptr;
}