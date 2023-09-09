// DATE: 10-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1
// Question: Insert a Node in a BST
// Description: For a given value data insert it into the BST if its not present, else don't modify the tree.
// Approach: 1. Basic BST creation-node insertion strategy.

class Solution
{
    public:
    Node* insert(Node* node, int data) {
        if(node == NULL){
            struct Node* nn = new Node(data);
            return nn;
        }
        if(node->data == data) return node;
        
        else if(node->data < data){
            node->right = insert(node->right, data);
        }
        else{
            node->left = insert(node->left, data);
        }
        
        return node;
    }
    
};