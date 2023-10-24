// DATE: 24-OCT-2023
// Question URL: https://leetcode.com/problems/find-largest-value-in-each-tree-row/

// Question: 515. Find Largest Value in Each Tree Row
// Description: Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
// Approach: 1. At each level compare the maximum in that level so far and update as necessary.

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> levels(0, 0);
        int size = 0;

        solve(root, levels, size, 0);

        return levels;
    }

    void solve(TreeNode* root, vector<int>& levels, int& size, int level){
        if(root == NULL) return;
        
        if(size <= level){
            size++;
            levels.push_back(root->val);
        }
        else if(levels[level] < root->val) levels[level] = root->val;

        solve(root->left, levels, size, level+1);
        solve(root->right, levels, size, level+1);
    }
};