// DATE: 22-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

// Question: Diagonal sum in binary tree
// Description: Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is the sum of all node datas lying between these lines. Given a Binary Tree of size n, print all diagonal sums.

//              For the following input tree, output should be 9, 19, 42.
//              9 is sum of 1, 3 and 5.
//              19 is sum of 2, 6, 4 and 7.
//              42 is sum of 9, 10, 11 and 12.
// Approach: 1. For every node append left child to new level and right child to same level of sum in vector.

class Solution
{
    public:
    void solve(Node* root, int idx, vector<int>& ans){
        if(root == NULL) return;
        
        if(ans.size() > idx){
            ans[idx] += root->data;
        }
        else{
            ans.push_back(root->data);
        }
        
        solve(root->left, idx+1, ans);
        solve(root->right, idx, ans);
    }
    
    vector <int> diagonalSum(Node* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};