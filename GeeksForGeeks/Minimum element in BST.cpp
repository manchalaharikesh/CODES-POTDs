// DATE: 30-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
// Question: Minimum element in BST
// Description: Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.
// Approach: 1. Code is Self-Explanatory.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
        if(root == NULL) return INT_MAX;
        
        return min(root->data, minValue(root->left));
    }
};