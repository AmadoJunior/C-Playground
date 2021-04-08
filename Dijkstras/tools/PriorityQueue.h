#ifndef PRIORITY_QUEUE_CLASS
#define PRIORITY_QUEUE_CLASS

#include <vector>
#include <string>

struct Task{
    char item;
    int priority;
    Task();
    Task(char, int);
};

class PriorityQueue{
    private:
        std::vector<Task> taskQueue;
    public:
        PriorityQueue();
        static void swap(int index1, int index2, std::vector<Task> &taskQueue);
        void enqueue(char item, int priority);
        Task dequeue();
        void cascadeUp();
        void cascadeDown();
        //Getters
        int getParentIndex(int childIndex);
        int getLeftChildIndex(int parentIndex);
        int getRightChildIndex(int parentIndex);
        int getSize();
};

#endif