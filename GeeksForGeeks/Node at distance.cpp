// DATE: 06-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/node-at-distance/1

// Question: Node at distance
// Description: Given a binary tree with n nodes and a positive integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
//              Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.
// Approach: 1. From each node look in its subtree for leaf nodes at k distance (O(Nlog(N)).

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    
    bool isLeafAtK(Node* root, int k){
        if(root == NULL) return false;
        if(k == 0 && root->left == NULL && root->right == NULL) return true;  
        else if(k == 0) return false;
        
        return isLeafAtK(root->left, k-1) || isLeafAtK(root->right, k-1);
    }
    
    int preorder(Node* root, int k){
        if(root == NULL) return 0;
        
        int ans = isLeafAtK(root, k) ? 1 : 0;
        ans += preorder(root->left, k);
        ans += preorder(root->right, k);
        
        return ans;
    }
    
    int printKDistantfromLeaf(Node* root, int k)
    {
        return preorder(root, k); 
    }
};