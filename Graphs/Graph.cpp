<<<<<<< HEAD
//
// Created by amado on 10/3/20.
//
#include "Graph.h"
#include <queue>

Graph::Graph(){}

void Graph::addVertex(std::string vertexKey) {
    if(!adjacencyList.count(vertexKey)){
        std::vector<std::string> emptyVector;
        std::pair<std::vector<std::string>, bool> pair(emptyVector, false);
        adjacencyList[vertexKey] = pair;
    }
}

void Graph::addEdge(std::string vertexKey1, std::string vertexKey2) {
    //If Vertices Exist
    if(adjacencyList.count(vertexKey1) && adjacencyList.count(vertexKey2)){
        //Add them to the list of vertices
        adjacencyList[vertexKey1].first.push_back(vertexKey2);
        adjacencyList[vertexKey2].first.push_back(vertexKey1);
    }
}

void Graph::removeEdge(std::string vertexKey1, std::string vertexKey2) {
    //If The Vertices Exist
    if(adjacencyList.count(vertexKey1) && adjacencyList.count(vertexKey2)){
        //Temporary Vector
        std::vector<std::string> tempVector;

        //Filling Vertex1
        for(int i = 0; i < adjacencyList[vertexKey1].first.size(); i++){
            if(adjacencyList[vertexKey1].first[i] != vertexKey2){
                tempVector.push_back(adjacencyList[vertexKey1].first[i]);
            }
        }
        adjacencyList[vertexKey1].first = tempVector;
        tempVector.clear();

        //Filling Vertex2
        for(int i = 0; i < adjacencyList[vertexKey2].first.size(); i++){
            if(adjacencyList[vertexKey2].first[i] != vertexKey1){
                tempVector.push_back(adjacencyList[vertexKey2].first[i]);
            }
        }
        adjacencyList[vertexKey2].first = tempVector;
        tempVector.clear();
    }
}

void Graph::removeVertex(std::string vertexKey) {
        //Loop to Remove Associated Edges
        for(int i = 0; i < adjacencyList[vertexKey].first.size(); i++){
            removeEdge(vertexKey, adjacencyList[vertexKey].first[i]);
        }

        //Removing Vertex
        adjacencyList.erase(vertexKey);
}

std::vector<std::string> Graph::DFSRecursive(std::string start){
    //Resetting Visited Status
    std::map<std::string, std::pair<std::vector<std::string>, bool>>::iterator it = adjacencyList.begin();
    while(it != adjacencyList.end()){
        adjacencyList[it->first].second = false;
        it++;
    }

    //Init Result
    std::vector<std::string> result;
    //Run Helper
    DFSHelper(start, result);

    return result;
}

int Graph::DFSHelper(std::string start, std::vector<std::string> &result) {
    //Edge
    if(!adjacencyList.count(start)){
        return 0;
    }

    //Adding to Vector and Marking
    result.push_back(start);
    adjacencyList[start].second = true;

    //For Every Neighbor not Visited => Run DFS(neighborKey)
    for(std::string neighborKey : adjacencyList[start].first){
        if(adjacencyList[neighborKey].second){
            continue;
        } else {
            DFSHelper(neighborKey, result);
        }
    }
}

std::vector<std::string> Graph::DFSIterative(std::string start) {
    //Resetting Visited Status
    std::map<std::string, std::pair<std::vector<std::string>, bool>>::iterator it = adjacencyList.begin();
    while(it != adjacencyList.end()){
        adjacencyList[it->first].second = false;
        it++;
    }
    //Initializing Stack and Result
    std::vector<std::string> result;
    std::vector<std::string> stack;

    //Adding First Item to Stack
    stack.push_back(start);

    //While there are items left int the stack
    while(stack.size() > 0){
        //Pop a vertexKey from the end
        std::string currentVertex = stack[stack.size()-1];
        stack.pop_back();
        //Adding to Result
        result.push_back(currentVertex);
        //For Each Neighbor
            //Check if neighbor has been visited and add to the stack
        for(std::string neighbor : adjacencyList[currentVertex].first){
            if(!adjacencyList[neighbor].second){
                adjacencyList[neighbor].second = true;
                stack.push_back(neighbor);
            }
        }
    }
    return result;
}

std::vector<std::string> Graph::BFS(std::string start) {
    //Resetting Visited Status
    std::map<std::string, std::pair<std::vector<std::string>, bool>>::iterator it = adjacencyList.begin();
    while(it != adjacencyList.end()){
        adjacencyList[it->first].second = false;
        it++;
    }
    //Initializing Stack and Result
    std::vector<std::string> result;
    std::queue<std::string> queue;

    //Adding First Item to Stack
    queue.push(start);
    adjacencyList[queue.front()].second = true;

    //While there are items left int the stack
    while(queue.size() > 0){
        //Pop a vertexKey from the end
        std::string currentVertex = queue.front();
        queue.pop();
        //Adding to Result
        result.push_back(currentVertex);
        //For Each Neighbor
        //Check if neighbor has been visited and add to the stack
        for(std::string neighbor : adjacencyList[currentVertex].first){
            if(!adjacencyList[neighbor].second){
                adjacencyList[neighbor].second = true;
                queue.push(neighbor);
            }
        }
    }
    return result;
}
=======
//
// Created by amado on 10/3/20.
//
#include "Graph.h"
#include <queue>

Graph::Graph(){}

void Graph::addVertex(std::string vertexKey) {
    if(!adjacencyList.count(vertexKey)){
        std::vector<std::string> emptyVector;
        std::pair<std::vector<std::string>, bool> pair(emptyVector, false);
        adjacencyList[vertexKey] = pair;
    }
}

void Graph::addEdge(std::string vertexKey1, std::string vertexKey2) {
    //If Vertices Exist
    if(adjacencyList.count(vertexKey1) && adjacencyList.count(vertexKey2)){
        //Add them to the list of vertices
        adjacencyList[vertexKey1].first.push_back(vertexKey2);
        adjacencyList[vertexKey2].first.push_back(vertexKey1);
    }
}

void Graph::removeEdge(std::string vertexKey1, std::string vertexKey2) {
    //If The Vertices Exist
    if(adjacencyList.count(vertexKey1) && adjacencyList.count(vertexKey2)){
        //Temporary Vector
        std::vector<std::string> tempVector;

        //Filling Vertex1
        for(int i = 0; i < adjacencyList[vertexKey1].first.size(); i++){
            if(adjacencyList[vertexKey1].first[i] != vertexKey2){
                tempVector.push_back(adjacencyList[vertexKey1].first[i]);
            }
        }
        adjacencyList[vertexKey1].first = tempVector;
        tempVector.clear();

        //Filling Vertex2
        for(int i = 0; i < adjacencyList[vertexKey2].first.size(); i++){
            if(adjacencyList[vertexKey2].first[i] != vertexKey1){
                tempVector.push_back(adjacencyList[vertexKey2].first[i]);
            }
        }
        adjacencyList[vertexKey2].first = tempVector;
        tempVector.clear();
    }
}

void Graph::removeVertex(std::string vertexKey) {
        //Loop to Remove Associated Edges
        for(int i = 0; i < adjacencyList[vertexKey].first.size(); i++){
            removeEdge(vertexKey, adjacencyList[vertexKey].first[i]);
        }

        //Removing Vertex
        adjacencyList.erase(vertexKey);
}

std::vector<std::string> Graph::DFSRecursive(std::string start){
    //Resetting Visited Status
    std::map<std::string, std::pair<std::vector<std::string>, bool>>::iterator it = adjacencyList.begin();
    while(it != adjacencyList.end()){
        adjacencyList[it->first].second = false;
        it++;
    }

    //Init Result
    std::vector<std::string> result;
    //Run Helper
    DFSHelper(start, result);

    return result;
}

int Graph::DFSHelper(std::string start, std::vector<std::string> &result) {
    //Edge
    if(!adjacencyList.count(start)){
        return 0;
    }

    //Adding to Vector and Marking
    result.push_back(start);
    adjacencyList[start].second = true;

    //For Every Neighbor not Visited => Run DFS(neighborKey)
    for(std::string neighborKey : adjacencyList[start].first){
        if(adjacencyList[neighborKey].second){
            continue;
        } else {
            DFSHelper(neighborKey, result);
        }
    }
}

std::vector<std::string> Graph::DFSIterative(std::string start) {
    //Resetting Visited Status
    std::map<std::string, std::pair<std::vector<std::string>, bool>>::iterator it = adjacencyList.begin();
    while(it != adjacencyList.end()){
        adjacencyList[it->first].second = false;
        it++;
    }
    //Initializing Stack and Result
    std::vector<std::string> result;
    std::vector<std::string> stack;

    //Adding First Item to Stack
    stack.push_back(start);

    //While there are items left int the stack
    while(stack.size() > 0){
        //Pop a vertexKey from the end
        std::string currentVertex = stack[stack.size()-1];
        stack.pop_back();
        //Adding to Result
        result.push_back(currentVertex);
        //For Each Neighbor
            //Check if neighbor has been visited and add to the stack
        for(std::string neighbor : adjacencyList[currentVertex].first){
            if(!adjacencyList[neighbor].second){
                adjacencyList[neighbor].second = true;
                stack.push_back(neighbor);
            }
        }
    }
    return result;
}

std::vector<std::string> Graph::BFS(std::string start) {
    //Resetting Visited Status
    std::map<std::string, std::pair<std::vector<std::string>, bool>>::iterator it = adjacencyList.begin();
    while(it != adjacencyList.end()){
        adjacencyList[it->first].second = false;
        it++;
    }
    //Initializing Stack and Result
    std::vector<std::string> result;
    std::queue<std::string> queue;

    //Adding First Item to Stack
    queue.push(start);
    //Marking First Element as Visited
    adjacencyList[queue.front()].second = true;

    //While there are items left int the stack
    while(queue.size() > 0){
        //Pop a vertexKey from the end
        std::string currentVertex = queue.front();
        queue.pop();
        //Adding to Result
        result.push_back(currentVertex);
        //For Each Neighbor
        //Check if neighbor has been visited and add to the stack
        for(std::string neighbor : adjacencyList[currentVertex].first){
            if(!adjacencyList[neighbor].second){
                adjacencyList[neighbor].second = true;
                queue.push(neighbor);
            }
        }
    }
    return result;
}
>>>>>>> 06643cfd12977568bd0ce44e4c271c7ea777e736
