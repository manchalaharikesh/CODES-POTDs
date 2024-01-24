// DATE: 24-JAN-2024
// Question URL: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/

// Question: 1457. Pseudo-Palindromic Paths in a Binary Tree
// Description: Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

//              Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
// Approach: 1. Have a VAR(_xor) and for occurence of 0 make 0th bit set, of 1 make 1st bit set, .... and finally if _xor = 0 or only one set bit is in _xor INC(ans).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int& _xor, int& ans){
        _xor = _xor ^ (1 << root->val);

        if(root->left == NULL && root->right == NULL){
            if(_xor == 0 || ((1 << (int)log2(_xor)) - 1 == _xor - 1)){
                ans++;
            }
        }

        if(root->left != NULL) dfs(root->left, _xor, ans);
        if(root->right != NULL) dfs(root->right, _xor, ans);

        _xor = _xor ^ (1 << root->val);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0, _xor = 0;

        dfs(root, _xor, ans);

        return ans;
    }
};