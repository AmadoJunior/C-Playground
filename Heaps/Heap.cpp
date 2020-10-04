#include "Heap.h"
#include <math.h>

Heap::Heap(){

}

void Heap::insert(int value){
    values.push_back(value);
    bubbleUp();
}

void Heap::swap(std::vector<int>& values, int index1, int index2){
    int temp = values[index1];
    values[index1] = values[index2];
    values[index2] = temp;
}

void Heap::bubbleUp(){
    int index = values.size()-1;
    while(index > 0){
        int parentIndex = getParentIndex(index);
        if(values[index] <= values[parentIndex]){
            break;
        }
        swap(values, parentIndex, index);
        index = parentIndex;
    }
}

int Heap::extractMax(){
    int max = values[0];
    int end = values[values.size()-1];
    values.pop_back();
    if(values.size() > 0){
        values[0] = end;
        sinkDown();
    }
    return max;
}

void Heap::sinkDown(){
    int index = 0;

    while(true){
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int leftChild, rightChild;
        int swapIndex = -1;

        if(leftChildIndex < values.size()){
            leftChild = values[leftChildIndex];
            if(leftChild > values[index]){
                swapIndex = leftChildIndex;
            }
        }

        if(rightChildIndex < values.size()) {
            rightChild = values[rightChildIndex];
            if(
                    (swapIndex == -1 && rightChild > values[index]) ||
                    (swapIndex != -1 && rightChild > leftChild)
            ){
                swapIndex = rightChildIndex;
            }
        }

        if(swapIndex == -1){
            break;
        }

        swap(values, index, swapIndex);
        index = swapIndex;
    }

}

//Getters


int Heap::getParentIndex(int index){
    return floor((index-1)/2);
}

int Heap::getLeftChildIndex(int index) {
    return 2 * index + 1;
}

int Heap::getRightChildIndex(int index) {
    return 2 * index + 2;
}

int Heap::heapSize(){
    return values.size();
}