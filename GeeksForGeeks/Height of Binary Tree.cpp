// DATE: 09-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// Question: Height of Binary Tree
// Description: Given a binary tree, find its height.
// Approach: 1. Code - Self Explanatory.

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node == NULL){
            return 0;
        }
        return 1+max(height(node->left), height(node->right));
    }
};