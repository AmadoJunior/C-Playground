#include "WeightedGraph.h"
#include "tools/PriorityQueue.h"
#include <limits>

Edge::Edge(char neighborKey, int weight) : neighborKey(neighborKey), weight(weight) {

}

WeightedGraph::WeightedGraph(){}

void WeightedGraph::addVertex(char vertexKey){
    if(!adjacencyList.count(vertexKey)){
        std::vector<Edge> newVector;
        adjacencyList.insert(std::pair<char, std::vector<Edge>>(vertexKey, newVector));
    }
}

void WeightedGraph::addEdge(char vertexKey1, char vertexKey2, int weight){
    if(adjacencyList.count(vertexKey1) && adjacencyList.count(vertexKey2)){
        adjacencyList[vertexKey1].push_back(Edge(vertexKey2, weight));
        adjacencyList[vertexKey2].push_back(Edge(vertexKey1, weight));
    }
}

void WeightedGraph::removeEdge(char vertexKey1, char vertexKey2){
    /*
        s1 = size of edge array at vertexKey1
        s2 = size of edge array at vertexKey2
        TC : O(s1 + s2)
        SC : O( max(s1.size(), s2.size()) ) - Biggest Array is Worst Case
    */
    if(adjacencyList.count(vertexKey1) && adjacencyList.count(vertexKey2)){
        std::vector<Edge> tempVector;
        for(Edge edge1 : adjacencyList[vertexKey1]){
            if(edge1.neighborKey != vertexKey2){
                tempVector.push_back(edge1);
            }
        }
        adjacencyList[vertexKey1] = tempVector;
        tempVector.clear();
        for(Edge edge2 : adjacencyList[vertexKey2]){
            if(edge2.neighborKey != vertexKey1){
                tempVector.push_back(edge2);
            }
        }
        adjacencyList[vertexKey2] = tempVector;
    }
}

void WeightedGraph::removeVertex(char vertexKey){
    if(adjacencyList.count(vertexKey)){
        for(Edge edge : adjacencyList[vertexKey]){
            removeEdge(vertexKey, edge.neighborKey);
        }
        adjacencyList.erase(vertexKey);
    }
}

std::vector<char> WeightedGraph::findShortestPath(char startKey, char targetKey){
    std::vector<char> result;
    PriorityQueue queue;
    std::map<char, char> previous;
    std::map<char, int> distances;
    char smallest;
    std::map<char, std::vector<Edge>>::iterator it = adjacencyList.begin();
    //Initial State
    while(it != adjacencyList.end()){
        if(it->first == startKey){
            distances.insert(std::pair<char, int>(it->first, 0));
            queue.enqueue(it->first, distances[it->first]);
        }
        previous.insert(std::pair<char, char>(it->first, 0));
        distances.insert(std::pair<char, int>(it->first, INT16_MAX));
        queue.enqueue(it->first, distances[it->first]);
        it++;
    }
    //Main Loop
    while(queue.getSize() > 0){
        char smallest = queue.dequeue().item;
        if(smallest == targetKey){
            //We are done
            //Build up path to return at end
            char current = smallest;
            while(current){
                result.push_back(current);
                current = previous[current];
            }
            break;
        }
        if(smallest && distances[smallest] != INT16_MAX){
            for(Edge edge : adjacencyList[smallest]){
                //Calculate Distance from Neighboring Node
                int candidate = distances[smallest] + edge.weight;
                if(candidate < distances[edge.neighborKey]){
                    //Updating New Smallest Dist to Neighbor
                    distances[edge.neighborKey] = candidate;
                    //Updating Previous
                    previous[edge.neighborKey] = smallest;
                    //Enqueue in PQ With New Priority
                    queue.enqueue(edge.neighborKey, candidate);
                }
            }
        }
    }
    return result;
}
