// DATE: 25-JUN-2024
// Question URL: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

// Question: 1038. Binary Search Tree to Greater Sum Tree
// Description: Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

//              As a reminder, a binary search tree is a tree that satisfies these constraints:

//              The left subtree of a node contains only nodes with keys less than the node's key.
//              The right subtree of a node contains only nodes with keys greater than the node's key.
//              Both the left and right subtrees must also be binary search trees.
// Approach: 1. Given that the tree is strictly BST. Then as to convert it into a greater sum tree we need to update curr root with sum of values of roots greater to it. This is achieved by reverse inorder traversal.
//              For better understanding refer to code.

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
    void revInorder(TreeNode* root, int& sum){
        if(root == NULL) return ;

        revInorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        revInorder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;

        revInorder(root, sum);

        return root;
    }
};