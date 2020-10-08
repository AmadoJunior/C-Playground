#ifndef WEIGHTED_GRAPH_CLASS
#define WEIGHTED_GRAPH_CLASS

#include <map>
#include <vector>
#include <string>

struct Edge{
    char neighborKey;
    int weight;
    Edge(char neighborKey, int weight);
};

class WeightedGraph{
    private:
        std::map<char, std::vector<Edge>> adjacencyList;
    public:
        WeightedGraph();
        void addVertex(char vertexKey);
        void removeVertex(char vertexKey);
        void addEdge(char vertexKey1, char vertexKey2, int weight);
        void removeEdge(char vertexKey1, char vertexKey2);
        std::vector<char> findShortestPath(char startKey, char targetKey);
};

#endif