// DATE: 03-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/is-it-a-tree/1
// Question: K distance from roo
// Description: Given a binary tree having n nodes and an integer k. Print all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be printed from left to right.
// Approach: 1. Brute Force / Code Self Explanatory.

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
    public:
    // function should print the nodes at k distance from root
    void dfs(struct Node* root, int k, vector<int>& ans){
        if(root == NULL) return ;
        if(k == 0){
            ans.push_back(root->data);
            return ;
        }
        
        dfs(root->left, k-1, ans);
        dfs(root->right, k-1, ans);
    }
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> ans;
        
        dfs(root, k, ans);
        
        return ans;
    }
};