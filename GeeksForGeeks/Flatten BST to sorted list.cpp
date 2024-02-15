// DATE: 16-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

// Question: Flatten BST to sorted list
// Description: You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

//              Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.
// Approach: 1. Brute Force Self-Explanatory.

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    void inorder(Node* root, vector<Node*>& v){
        if(root == NULL) return ;
        
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    Node *flattenBST(Node *root)
    {
        vector<Node*> v;
        
        inorder(root, v);
        
        v[v.size()-1]->left = NULL;
        v[v.size()-1]->right = NULL;
        
        for(int i = 0; i < v.size()-1; i++){
            v[i]->left = NULL;
            v[i]->right = NULL;
            v[i]->right = v[i+1];
        }
        
        return v[0];
    }
};