#include "PriorityQueue.h"
#include <math.h>

Task::Task(){}
Task::Task(char item, int priority) : item(item), priority(priority) {}

PriorityQueue::PriorityQueue(){}

void PriorityQueue::swap(int index1, int index2, std::vector<Task> &taskQueue){
    Task temp = taskQueue[index1];
    taskQueue[index1] = taskQueue[index2];
    taskQueue[index2] = temp;
}

void PriorityQueue::enqueue(char item, int priority){
    taskQueue.push_back(Task(item, priority));
    cascadeUp();
}

Task PriorityQueue::dequeue(){
    Task max = taskQueue[0];
    Task end = taskQueue[taskQueue.size()];
    taskQueue.pop_back();
    if(taskQueue.size() > 0){
        taskQueue[0] = end;
        cascadeDown();
    }
    return max;
}

void PriorityQueue::cascadeUp(){
    int currentIndex = taskQueue.size()-1;
    while(currentIndex > 0){
        int parentIndex = getParentIndex(currentIndex);
        if(taskQueue[parentIndex].priority > taskQueue[currentIndex].priority){
            swap(currentIndex, parentIndex, taskQueue);
            currentIndex = parentIndex;
        } else {
            break;
        }
    }
}

void PriorityQueue::cascadeDown(){
    int currentIndex = 0;
    while(true){
        int leftChildIndex = getLeftChildIndex(currentIndex);
        int rightChildIndex = getRightChildIndex(currentIndex);
        Task leftChild, rightChild;
        int swapIndex = -1;
        //If leftChild is bigger than parent
        if(leftChildIndex < taskQueue.size()-1){
            leftChild = taskQueue[leftChildIndex];
            if(leftChild.priority < taskQueue[currentIndex].priority){
                swapIndex = leftChildIndex;
            }
        }
        //If leftChild is smaller than parent but rightChild is bigger
        //Or if leftChild is bigger than parent but rightChild is bigger than leftChild
        if(rightChildIndex < taskQueue.size()-1){
            rightChild = taskQueue[rightChildIndex];
            if(
                (swapIndex == -1 && rightChild.priority < taskQueue[currentIndex].priority) ||
                (swapIndex != -1 && rightChild.priority < leftChild.priority)
            ){
                swapIndex = rightChildIndex;
            }
        }
        //If there are not swaps
        if(swapIndex == -1){
            break;
        }
        swap(swapIndex, currentIndex, taskQueue);
        currentIndex = swapIndex;
    }
}

//Getters
int PriorityQueue::getParentIndex(int childIndex){
    return floor((childIndex-1) / 2);
}

int PriorityQueue::getLeftChildIndex(int parentIndex){
    return parentIndex * 2 + 1;
}

int PriorityQueue::getRightChildIndex(int parentIndex){
    return parentIndex * 2 + 2;
}

int PriorityQueue::getSize(){
    return taskQueue.size();
}