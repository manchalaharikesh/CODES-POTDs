// DATE: 12-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

// Question: Root to leaf path sum
// Description: Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.
// Approach: 1. Brute Force Code is Self-Explanatory.

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool solve(Node* root, int target, bool& res){
        if(root->left == NULL && root->right == NULL){
            if(target-root->data == 0) res = true;
            else res = false;
        }
        
        if(root->left != NULL) solve(root->left, target-root->data, res);
        if(root->right != NULL && !res)  solve(root->right, target-root->data, res);
    }
    bool hasPathSum(Node *root, int target) {
        bool res = false;
        
        solve(root, target, res);
        
        return res;
    }
};