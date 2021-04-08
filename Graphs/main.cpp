#include <iostream>
#include "Graph.h"

int main() {
    Graph myGraph;
    myGraph.addVertex("A");
    myGraph.addVertex("B");
    myGraph.addVertex("C");
    myGraph.addVertex("D");
    myGraph.addVertex("E");
    myGraph.addVertex("F");

    myGraph.addEdge("A", "B");
    myGraph.addEdge("A", "C");
    myGraph.addEdge("B", "D");
    myGraph.addEdge("C", "E");
    myGraph.addEdge("D", "E");
    myGraph.addEdge("D", "F");
    myGraph.addEdge("E", "F");

    std::vector<std::string> temp;
    temp = myGraph.BFS("A");

    for(std::string s : temp){
        std::cout << s << std::endl;
    }


    return 0;
}
