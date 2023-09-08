// DATE: 09-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// Question: Kth Largest Element in BST
// Description: For a given BST find the kth largest element.
// Approach: 1. Inorder (left, curr, right) traversal of BST gives you ascending order in general.
//              But performing the reverse of it (right, curr, left) gives you descending order.
//              Use it to find the kth largest element.

class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        int ans = solve(root, K);
        return ans;
    }
    
    int solve(Node* root, int& k){
        if(root->right != NULL && k > 0){
            int ans = solve(root->right, k);
            if(ans != -1) return ans;
        }
        k--;
        if(root->left != NULL && k > 0){
            int ans = solve(root->left, k);
            if(ans != -1) return ans;
        }
        
        if(k == 0) return root->data;
        return -1;
    }
};