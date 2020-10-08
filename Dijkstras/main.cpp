#include <iostream>
#include "WeightedGraph.h"
#include <vector>

int main(){
    std::vector<char> result;
    WeightedGraph myGraph;

    myGraph.addVertex('A');
    myGraph.addVertex('B');
    myGraph.addVertex('C');
    myGraph.addVertex('D');
    myGraph.addVertex('E');
    myGraph.addVertex('F');
    myGraph.addEdge('A', 'B', 4);
    myGraph.addEdge('A', 'C', 2);
    myGraph.addEdge('B', 'E', 3);
    myGraph.addEdge('C', 'D', 2);
    myGraph.addEdge('C', 'F', 4);
    myGraph.addEdge('D', 'E', 3);
    myGraph.addEdge('D', 'F', 1);
    myGraph.addEdge('E', 'F', 1);

    result = myGraph.findShortestPath('A', 'E');
    for(int i = result.size()-1; i >= 0; i--){
        std::cout << result[i] << std::endl;
    }
    
    return 0;
}