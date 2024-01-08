// DATE: 08-JAN-2024
// Question URL: https://leetcode.com/problems/range-sum-of-bst/description/

// Question: 938. Range Sum of BST
// Description: Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
// Approach: 1. Tree Traversal algorithms.

class Solution {
public:
    void solve(TreeNode* root, int low, int high, int& sum){
        if(root == NULL) return ;
        
        sum += root->val >= low && root->val <= high ? root->val : 0;
        solve(root->left, low, high, sum);
        solve(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        solve(root, low, high, sum);

        return sum;
    }
};