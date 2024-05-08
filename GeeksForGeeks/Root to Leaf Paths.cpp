// DATE: 08-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

// Question: Root to Leaf Paths
// Description: Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.
// Approach: 1. Store each element in a path into a vector v and when we traverse back from the path pop_back() element. And at each leaf node store v into a vector of vectors.

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int> v, vector<vector<int>>& ans){
        if(root == NULL) return ;
        
        v.push_back(root->data);
        
        if(root->left == NULL && root->right == NULL){
             ans.push_back(v);
        }
        else{
            inorder(root->left, v, ans);
            inorder(root->right, v, ans);
        }
        
        v.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> v;
        
        inorder(root, v, ans);
        
        return ans;
    }
};