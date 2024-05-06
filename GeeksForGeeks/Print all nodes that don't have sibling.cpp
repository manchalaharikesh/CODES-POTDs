// DATE: 06-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1
// Question: Print all nodes that don't have sibling
// Description: Given a Binary Tree of n nodes, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order (Increasing).

//              Two nodes are said to be siblings if they are present at the same level, and their parents are the same.

//              Note: The root node can not have a sibling so it cannot be included in our answer.
// Approach: 1. Brute Force / Code is Self-Explanatory.

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void inorder(Node* node, vector<int>& ans){
    if(node == NULL) return ;
    
    if(node->left == NULL && node->right != NULL) ans.push_back(node->right->data);
    if(node->left != NULL && node->right == NULL) ans.push_back(node->left->data);
    
    inorder(node->left, ans);
    inorder(node->right, ans);
}

vector<int> noSibling(Node* node)
{
    vector<int> ans;
    inorder(node, ans);
    
    sort(ans.begin(), ans.end());
    
    if(ans.size() == 0) ans.push_back(-1);
    
    return ans;
}