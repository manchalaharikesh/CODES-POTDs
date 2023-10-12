// DATE: 12-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
// Question: Duplicate subtree in Binary Tree
// Description: Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

//              Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.
// Approach: 1. By doing preorder traversals store all possible valid subtrees from curr node in a set then when we find a subtree existing in set already we return true.

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        set<vector<char>> s;
        
        if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        
        return solve(root, s) ? 1 : 0;
    }
    
    bool solve(Node *root, set<vector<char>>& s){
        if(root->left != NULL || root->right != NULL){
            vector<char> v;
            getInorder(root, v);
            if(s.find(v) == s.end()) s.insert(v);
            else return true;
        }
        else return false;
        
        bool status1, status2;
        if(root->left != NULL) status1 = solve(root->left, s);
        if(root->right != NULL) status2 = solve(root->right, s);
        
        return status1 || status2;
    }
    
    void getInorder(Node *root, vector<char>& v){
        if(root == NULL){
            v.push_back('N');
            return;
        }
        
        getInorder(root->left, v);
        v.push_back((char)(root->data));
        getInorder(root->right, v);
    }
};