// DATE: 05-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1
// Question: Vertical Width of a Binary Tree
// Description: Given a Binary Tree. You need to find and return the vertical width of the tree.
// Approach: 1. To find the width we need to find the maximum possible left width and maximum possible right width from root.
//              This can be done similar to the vertical order traversal algorithm of binary tree.
//              Let any parent of subtree be at width w from root node, then for each further left iteration we make width as w-1 and each further right iteration we make width as w+1.
//              We always store the minimum w as l, maximum w as r (shows the maximum possible left and right widths respectively).
//              The final answer be the r-l+1 (1 is for adding the root node itself as it adds up a single unit of width to final answer).
//              Please refer to code for better understanding.

class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    void solve(Node* root, int w, int& l, int& r){
        if(root == NULL) return ;
        
        solve(root->left, w-1, l, r);
        l = min(w, l);
        r = max(w, r);
        solve(root->right, w+1, l, r);
    }
    int verticalWidth(Node* root) {
        if(root == NULL) return 0;
        
        int l = INT_MAX, r = INT_MIN;
        
        solve(root, 0, l, r);
        
        return r - l + 1;
    }
};