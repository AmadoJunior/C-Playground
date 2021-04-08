//
// Created by amado on 10/3/20.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <map>
#include <string>
#include <vector>

/*
 *  Undirected Graph
 */

class Graph{
private:
    std::map<std::string, std::pair<std::vector<std::string>, bool>> adjacencyList;
public:
    Graph();
    void addVertex(std::string vertexKey);
    void addEdge(std::string vertexKey1, std::string vertexKey2);
    void removeEdge(std::string vertexKey1, std::string vertexKey2);
    void removeVertex(std::string vertexKey);
    //Depth First
    std::vector<std::string> DFSRecursive(std::string start);
    int DFSHelper(std::string start, std::vector<std::string> &result);
    std::vector<std::string> DFSIterative(std::string start);
    std::vector<std::string> BFS(std::string start);
};

#endif //GRAPHS_GRAPH_H
