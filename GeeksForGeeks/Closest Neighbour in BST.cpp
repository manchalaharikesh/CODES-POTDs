// DATE: 31-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1
// Question: Closest Neighbour in BST
// Description: Given the root of a binary search tree and a number n, find the greatest number in the binary search tree that is less than or equal to n. 
// Approach: 1. Code - Self Explanatory.

/*
//Structure of the Node of the BST is as
struct Node {
    int key;
    Node* left, *right;
};


   'N' is the element
   'size' is the total element in BST
  */

class Solution {
  public:
    int findNear(Node* root, int n, int val){
        if(root == NULL) return val;
        
        if(root->key <= n){
            val = max(val, root->key);
            return findNear(root->right, n, val);
        }
        else return findNear(root->left, n, val);
    }
    int findMaxForN(Node* root, int n) {
        int ans = findNear(root, n, 0);
        return ans == 0 ? -1 : ans;
    }
};