#include <iostream>
#include "PriorityQueue.h"

int main() {
    //My Queue
    PriorityQueue myQueue;

    //Test Tasks
    Task task1("Work", 8);
    Task task2("Study", 7);
    Task task3("Eat", 6);
    Task task4("Sleep", 3);
    Task task5("Watch Tv", 1);
    Task task6("Have Fun", 10);
    myQueue.queueTask(task1);
    myQueue.queueTask(task2);
    myQueue.queueTask(task3);
    myQueue.queueTask(task4);
    myQueue.queueTask(task5);
    myQueue.queueTask(task6);

    //Printing
    //myQueue.displayQueue();

    Task temp;
    temp = myQueue.dequeueTask();
    std::cout << "Priority: " + std::to_string(temp.priority) + "\n"
              << "Task Description: " << temp.task << std::endl;
    temp = myQueue.dequeueTask();
    std::cout << "Priority: " + std::to_string(temp.priority) + "\n"
              << "Task Description: " << temp.task << std::endl;
    Task task7("Urgent", 5);
    myQueue.queueTask(task7);
    temp = myQueue.dequeueTask();
    std::cout << "Priority: " + std::to_string(temp.priority) + "\n"
              << "Task Description: " << temp.task << std::endl;
    temp = myQueue.dequeueTask();
    std::cout << "Priority: " + std::to_string(temp.priority) + "\n"
              << "Task Description: " << temp.task << std::endl;
    temp = myQueue.dequeueTask();
    std::cout << "Priority: " + std::to_string(temp.priority) + "\n"
              << "Task Description: " << temp.task << std::endl;
    temp = myQueue.dequeueTask();
    std::cout << "Priority: " + std::to_string(temp.priority) + "\n"
              << "Task Description: " << temp.task << std::endl;
    temp = myQueue.dequeueTask();
    std::cout << "Priority: " + std::to_string(temp.priority) + "\n"
              << "Task Description: " << temp.task << std::endl;

    return 0;
}
