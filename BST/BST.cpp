#include <iostream>
#include "BST.h"
#include "Queue/Queue.h"

TreeNode::TreeNode(int value) : value(value) {
    left = nullptr;
    right = nullptr;
}

BST::BST(){
    root = nullptr;
}

void BST::insert(int value){
    TreeNode *newNode = new TreeNode(value);
    
    if(root == nullptr){
        root = newNode;
        return;
    } else {
        TreeNode *current = getRoot();

        while(true){
             if(current->value >= value){
                if(!current->left){
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
             } else if(current->value <= value){
                 if(!current->right){
                     current->right = newNode;
                     break;
                 } else {
                     current = current->right;
                 }
             }
        }
    }
}

void BST::insertRecursive(int value, TreeNode **current){
    if(*current == nullptr){
        TreeNode *newNode = new TreeNode(value);
        *current =  newNode;
    } else {
        if(value <= (*current)->value){
            insertRecursive(value, &(*current)->left);
        } else {
            insertRecursive(value, &(*current)->right);
        }
    }
}

TreeNode* BST::find(int value){
    TreeNode *current = getRoot();
    bool found = false;

    while(current && !found){
        if(value == current->value){
            found = true;
            return current;
        } else if(value <= current->value){
            current = current->left;
        } else if(value >= current->value){
            current = current->right;
        }
    }
}

std::vector<int> BST::BFS(){
    Queue *myQueue = new Queue();
    std::vector<int> visited;
    TreeNode *curNode = root;

    myQueue->enqueue(curNode);
    while(myQueue->length() != 0){
        curNode = myQueue->dequeue();
        visited.push_back(curNode->value);
        if(curNode->left){
            myQueue->enqueue(curNode->left);
        }
        if(curNode->right){
            myQueue->enqueue(curNode->right);
        }
    }
    return visited;
}

//DFS - Pre Order
std::vector<int> BST::DFSPreOrder(){
    //Initiating
    std::vector<int> visited;
    TreeNode *curNode = root;
    //Calling Helper Recursive Function
    DFSPreOrderHelper(curNode, &visited);
    //Return Filled Array
    return visited;
}

void BST::DFSPreOrderHelper(TreeNode* node, std::vector<int>* visited){
    //Push into Vector
    visited->push_back(node->value);
    if(node->left){
        DFSPreOrderHelper(node->left, visited);
    }
    if(node->right){
        DFSPreOrderHelper(node->right, visited);
    }
};

//DFS - Post Order
std::vector<int> BST::DFSPostOrder(){
    //Initiating
    std::vector<int> visited;
    TreeNode *curNode = root;
    //Calling Helper Recursive Function
    DFSPostOrderHelper(curNode, &visited);
    //Return Filled Array
    return visited;
}

void BST::DFSPostOrderHelper(TreeNode* node, std::vector<int>* visited){
    //Push into Vector
    if(node->left){
        DFSPostOrderHelper(node->left, visited);
    }
    if(node->right){
        DFSPostOrderHelper(node->right, visited);
    }
    visited->push_back(node->value);
};

//Getters
TreeNode* BST::getRoot(){
    return root;
}