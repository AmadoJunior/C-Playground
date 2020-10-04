#ifndef HEAPS_HEAP_H
#define HEAPS_HEAP_H
#include <vector>

class Heap{
private:
    std::vector<int> values;
public:
    Heap();
    void insert(int value);
    void bubbleUp();
    int extractMax();
    void sinkDown();
    static void swap(std::vector<int>& values, int index1, int index2);

    //Getters
    int getParentIndex(int index);
    int getLeftChildIndex(int index);
    int getRightChildIndex(int index);
    int heapSize();
};

#endif //HEAPS_HEAP_H
