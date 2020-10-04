//
// Created by amado on 10/3/20.
//

#ifndef PRIORITYQUEUE_TASK_H
#define PRIORITYQUEUE_TASK_H

#include <string>

class Task{
public:
    std::string task;
    int priority;
    Task();
    Task(std::string description, int priority);
};

#endif //PRIORITYQUEUE_TASK_H
