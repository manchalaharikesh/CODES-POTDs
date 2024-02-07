// DATE: 07-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
// Question: Min distance between two given nodes of a Binary Tree
// Description: Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. The given two nodes are guaranteed to be in the binary tree and all node values are unique.
// Approach: 1. Find Least Common Ansector (LCA) then through dfs find depth of LCA, a, b. Then compute the minimum distance accordingly.

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int dfs(Node* root, int x, vector<Node*>& s, int d){
        if(root == NULL) return 0;
        
        s.push_back(root);
        if(root->data == x) return d;
        
        int left = dfs(root->left, x, s, d+1);
        if(left == 0){
            int right = dfs(root->right, x, s, d+1);
            if(right == 0){
                s.pop_back();
                return 0;
            }
            else return right;
        }
        return left;
    }
    
    int findDist(Node* root, int a, int b) {
        int d1 = 0, d2 = 0, d3 = 0, n;
        vector<Node*> s1, s2;
        Node *common, *t1, *t2;
        
        d1 = dfs(root, a, s1, 0);
        d2 = dfs(root, b, s2, 0);
        
        n = min(s1.size(), s2.size());
        
        for(int i = 0; i < n; i++){
            t1 = s1[i];
            t2 = s2[i];
            if(t1 != t2) break;
            common = s1[i];
        }
        
        d3 = dfs(root, common->data, s1, 0);
        
        if(common->data == a) return d2 - d3;
        else if(common->data == b) return d1 - d3;
        
        return d1 + d2 - 2*d3;
    }
};