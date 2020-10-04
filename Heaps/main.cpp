#include <iostream>
#include "Heap.h"

int main() {
    Heap myHeap;
    myHeap.insert(1);
    myHeap.insert(3);
    myHeap.insert(6);
    myHeap.insert(5);
    myHeap.insert(9);
    myHeap.insert(8);
    myHeap.insert()

    std::cout << myHeap.extractMax() << std::endl;

    return 0;
}
