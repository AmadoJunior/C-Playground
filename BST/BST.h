#ifndef BST_CLASS_H
#define BST_CLASS_H

#include <vector>

class TreeNode{
    public:
        TreeNode *left;
        TreeNode *right;
        int value;
        TreeNode(int value);
};

class BST{
    private:
        TreeNode *root;
    public:
        BST();
        void insert(int value);
        void insertRecursive(int value, TreeNode **current);
        TreeNode* find(int val);
        std::vector<int> BFS();
    //Getters
        TreeNode* getRoot();
};

#endif