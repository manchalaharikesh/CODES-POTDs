// DATE: 15-JAN-2024
// Question URL: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

// Question: 2385. Amount of Time for Binary Tree to Be Infected
// Description: You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

//              Each minute, a node becomes infected if:

//              The node is currently uninfected.
//              The node is adjacent to an infected node.
//              Return the number of minutes needed for the entire tree to be infected.
// Approach: 1. Brute Force / Code is Self Explanatory.

class Solution {
public:
    void solve(TreeNode* root, int start, int val, int& ans,
               map<TreeNode*, int>& m, bool& found) {
        if (root == NULL)
            return;

        if (root->val == start) {
            m[root] = 0;
            found = true;
        }

        ans = max(val, ans);

        if (found) {
            solve(root->left, start, val + 1, ans, m, found);
            solve(root->right, start, val + 1, ans, m, found);
        } else {
            solve(root->left, start, val, ans, m, found);
            solve(root->right, start, val, ans, m, found);
        }

        if (m.find(root->left) != m.end()) {
            m[root] = m[root->left] + 1;
            ans = max(ans, m[root]);
            solve(root->right, start, m[root] + 1, ans, m, found);
        } else if (m.find(root->right) != m.end()) {
            m[root] = m[root->right] + 1;
            ans = max(ans, m[root]);
            solve(root->left, start, m[root] + 1, ans, m, found);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        bool found = false;
        map<TreeNode*, int> m;

        solve(root, start, 0, ans, m, found);
        return ans;
    }
};