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
        std::vector<int> DFSPreOrder();
        void DFSPreOrderHelper(TreeNode* node, std::vector<int>* visited);
        std::vector<int> DFSPostOrder();
        void DFSPostOrderHelper(TreeNode* node, std::vector<int>* visited);
    //Getters
        TreeNode* getRoot();
};

#endif