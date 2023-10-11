// DATE: 11-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
// Question: Check for Balanced Tree
// Description: For a given tree, check if it is balanced or not. A tree is balanced if the difference between the height of its left subtree and right subtree is not greater than 1  .
// Approach: 1. For every node calculate the height for its left subtree and right subtree recursively. At any point if node is not balanced start backtracking and return false otherwise return true.

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        int res = maxHeight(root);
        return res != -1;
    }
    
    int maxHeight(Node *root){
        if(root == NULL) return 0;
        
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        
        if(left == -1 || right == -1) return -1;
        
        return abs(left-right) <=1 ? max(left, right) + 1 : -1;
    }
};