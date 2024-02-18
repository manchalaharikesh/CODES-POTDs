// DATE: 18-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1
// Question: Sum of leaf nodes in BST
// Description: Given a Binary Search Tree with n nodes, find the sum of all leaf nodes. BST has the following property (duplicate nodes are possible):

//              The left subtree of a node contains only nodes with keys less than the node’s key.
//              The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
//              Your task is to determine the total sum of the values of the leaf nodes.

//              Note: Input array arr doesn't represent the actual BST, it represents the order in which the elements will be added into the BST.
// Approach: 1. Brute Force Code is Self-Explanatory.

/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */


class Solution
{
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             if(root == NULL) return 0;
             else if(root->left == NULL && root->right == NULL) return root->data;
             
             return sumOfLeafNodes(root->left) + sumOfLeafNodes(root->right);
        }
};