// DATE: 13-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/floor-in-bst/1
// Question: Floor in BST
// Description: You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
//              Note: when x is smaller than the smallest node of BST then returns -1.
// Approach: 1. Code - Self Explanatory.

class Solution{

public:
    int floor(Node* root, int x) {
        int ans = -1;
        
        solve(root, x, ans);
        
        return ans;
    }
    
    void solve(Node* root, int x, int& ans){
        if(root == NULL) return;
        
        if(root->data <= x && ans < root->data){
            ans = root->data;
        }
        
        if(root->data < x) solve(root->right, x, ans);
        else solve(root->left, x, ans);
    }
};