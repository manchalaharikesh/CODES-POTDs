// DATE: 02-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
// Question: Minimum Absolute Difference In BST
// Description: Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.
// Approach: 1. The inorder traversal always gives BST elements in sorted way. Thus the min of consecutive pairs abs diff is to be found.

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    public:
    void inorder(Node* root, int& ans, int& a){
        if(root == NULL) return ;
        
        inorder(root->left, ans, a);
        if(a == -1) a = root->data;
        else {
            ans = min(ans, abs(a-root->data));
            a = root->data;
        }
        inorder(root->right, ans, a);
    }
    int absolute_diff(Node *root)
    {
        int ans = INT_MAX, a = -1;
        inorder(root, ans, a);
        
        return ans;
    }
};