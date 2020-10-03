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
                } else {
                    current = current->left;
                }
             } else if(current->value <= value){
                 if(!current->right){
                     current->right = newNode;
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
        std::cout << curNode->value << std::endl;
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

//Getters
TreeNode* BST::getRoot(){
    return root;
}