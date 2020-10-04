#include "PriorityQueue.h"
#include "Task/Task.h"
#include <math.h>
#include <iostream>

PriorityQueue::PriorityQueue() {}

void PriorityQueue::swap(std::vector<Task> &taskQueue, int index1, int index2) {
    Task temp = taskQueue[index1];
    taskQueue[index1] = taskQueue[index2];
    taskQueue[index2] = temp;
}

void PriorityQueue::queueTask(Task task) {
    taskQueue.push_back(task);
    cascadeUp();
}

Task PriorityQueue::dequeueTask() {
    Task max = taskQueue[0];
    Task end = taskQueue[getPriorityQueueSize()-1];
    taskQueue.pop_back();
    if(getPriorityQueueSize() > 0){
        taskQueue[0] = end;
        cascadeDown();
    }
    return max;
}

void PriorityQueue::cascadeUp() {
    int index = taskQueue.size() - 1;
    while(index > 0){
        int parentIndex = getParentIndex(index);
        if(taskQueue[index].priority <= taskQueue[parentIndex].priority){
            break;
        }
        swap(taskQueue, parentIndex, index);
        index = parentIndex;
    }
}

void PriorityQueue::cascadeDown() {
    int index = 0;

    while(true){
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        Task leftChild, rightChild;
        int swapIndex  = -1;

        if(leftChildIndex < getPriorityQueueSize()){
            leftChild = taskQueue[leftChildIndex];
            if(leftChild.priority > taskQueue[index].priority){
                swapIndex = leftChildIndex;
            }
        }

        if(rightChildIndex < getPriorityQueueSize()){
            rightChild = taskQueue[rightChildIndex];
            if(
                    (swapIndex == -1 && rightChild.priority > taskQueue[index].priority) ||
                    (swapIndex != -1 && rightChild.priority > leftChild.priority)
            ){
                swapIndex = rightChildIndex;
            }
        }

        if(swapIndex == -1){
            break;
        }

        swap(taskQueue, index, swapIndex);
        index = swapIndex;
    }
}

void PriorityQueue::displayQueue() {
    for(int i = 0; i < taskQueue.size(); i++){
        std::cout << "Priority: " + std::to_string(taskQueue[i].priority) + "\n"
                << "Task Description: " << taskQueue[i].task << std::endl;
    }
}

//Getters
int PriorityQueue::getPriorityQueueSize() {
    return taskQueue.size();
}
int PriorityQueue::getParentIndex(int index){
    return floor((index-1)/2);
}
int PriorityQueue::getLeftChildIndex(int index){
    return 2 * index + 1;
}
int PriorityQueue::getRightChildIndex(int index){
    return 2 * index + 2;
}
