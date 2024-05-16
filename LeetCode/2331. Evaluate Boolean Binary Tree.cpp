// DATE: 16-MAY-2024
// Question URL: https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

// Question: 2331. Evaluate Boolean Binary Tree
// Description: You are given the root of a full binary tree with the following properties:

//              Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.
//              Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.
//              The evaluation of a node is as follows:

//              If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.
//              Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
//              Return the boolean result of evaluating the root node.

//              A full binary tree is a binary tree where each node has either 0 or 2 children.

//              A leaf node is a node that has zero children.
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
    bool evaluateTree(TreeNode* root) {
        if(root->val == 1 || root->val == 0) return root->val;

        int left = evaluateTree(root->left);

        if(root->val == 2){
            return  left || evaluateTree(root->right);
        }
        return left && evaluateTree(root->right);;
    }
};