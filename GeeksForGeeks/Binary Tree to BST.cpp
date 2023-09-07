// DATE: 08-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1
// Question: Binary Tree to BST
// Description: For a given binary tree, convert it into a binary search tree by preserving the tree structure.
// Approach: 1. Store elements into an array and sort it. Now update the tree by performing the inorder traversal with values in sorted array.

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> elements;
        
        getElements(root, elements);
        
        sort(elements.begin(), elements.end(), greater<int>());
        
        convertBinaryToBST(root, elements);
        
        return root;
    }
    
    void getElements(Node* root, vector<int>& elements){
        if(root == NULL) return;
        getElements(root->left, elements);
        elements.push_back(root->data);
        getElements(root->right, elements);
    }
    
    void convertBinaryToBST(Node* root, vector<int>& elements){
        if(root == NULL) return;
        convertBinaryToBST(root->left, elements);
        root->data = elements[elements.size()-1];
        elements.pop_back();
        convertBinaryToBST(root->right, elements);
    }
};