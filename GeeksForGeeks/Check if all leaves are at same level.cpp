// DATE: 08-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
// Question: Check if all leaves are at same level
// Description: Given a binary tree with n nodes, check if all leaves are at same level or not. Return true/false depending on whether all the leaf nodes are at the same level or not.
// Approach: 1. Code is Self-Explanatory.

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    int ans = -1;
    bool dfs(Node* root, int d){
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL){
            if(ans == -1){
                ans = d;
                return true;
            }
            else if(ans != d) return false;
        }
        
        return dfs(root->left, d+1) && dfs(root->right, d+1);
    }
    
    bool check(Node *root)
    {
        return dfs(root, 0);    
    }
};