//
// Created by amado on 10/3/20.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include <vector>
#include "Task/Task.h"

class PriorityQueue{
private:
    std::vector<Task> taskQueue;
public:
    PriorityQueue();
    void queueTask(Task task);  //Adds a Task
    Task dequeueTask();         //Returns Task De-queued
    void bubbleUp();            //Bubbles up the last item in the vector depending on priority
    void sinkDown();            //Sinks down the item at index 0 depending on priority
    static void swap(std::vector<Task> &vector, int index1, int index2);    //Static Swap
    //Getters
    int getParentIndex(int index);
    int getLeftChildIndex(int index);
    int getRightChildIndex(int index);
    int getPriorityQueueSize();
    void displayQueue();
};

#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
