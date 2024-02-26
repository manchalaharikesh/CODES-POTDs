// DATE: 26-FEB-2024
// Question URL: https://leetcode.com/problems/same-tree/description/

// Question: 100. Same Tree
// Description: Given the roots of two binary trees p and q, write a function to check if they are the same or not.

//              Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
// Approach: 1. Brute Force Code is Self-Explanatory.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL) return false;
        
        if(p->val == q->val) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else return false;
    }
};