#include <iostream>
#include "BST.h"

int main(){
    BST myTree;
    std::vector<int> result;

    myTree.insert(10);    
    myTree.insert(6);
    myTree.insert(15);
    myTree.insert(3);
    myTree.insert(8);
    myTree.insert(20);
    
    result = myTree.DFSPostOrder();

     for(int i = 0; i < result.size(); i++){
         std::cout << result[i] << std::endl;
     }

    return 0;
}