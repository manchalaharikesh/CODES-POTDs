// DATE: 20-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// Question: Sum of nodes on the longest path from root to leaf node
// Description: Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.
// Approach: 1. Brute Force Code is Self-Explanatory.

*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void dfs(Node* root, int& ans, int sum, int& max_dep, int d){
        if(root == NULL){
            if(d > max_dep){
                ans = sum;
                max_dep = d;
            }
            else if(d == max_dep && sum > ans) ans = sum;
            return ;
        }
        
        dfs(root->left, ans, sum + root->data, max_dep, d + 1);
        dfs(root->right, ans, sum + root->data, max_dep, d + 1);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int ans = 0, d = 0;
        
        dfs(root, ans, 0, d, 0);
        
        return ans;
    }
};