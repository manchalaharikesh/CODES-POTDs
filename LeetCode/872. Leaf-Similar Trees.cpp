// DATE: 09-JAN-2024
// Question URL: https://leetcode.com/problems/leaf-similar-trees/description/

// Question: 872. Leaf-Similar Trees
// Description: Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

//              For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

//              Two binary trees are considered leaf-similar if their leaf value sequence is the same.

//              Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
// Approach: 1. Store leaf seq in vectors and then compare them.

class Solution {
public:
    void getLeafSeq(TreeNode* root, vector<int>& seq){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) seq.push_back(root->val);

        getLeafSeq(root->left, seq);
        getLeafSeq(root->right, seq);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;

        getLeafSeq(root1, seq1);
        getLeafSeq(root2, seq2);

        int m = seq1.size(), n = seq2.size();

        if(m != n) return false;

        for(int i = 0; i < m; i++){
            if(seq1[i] != seq2[i]) return false;
        }

        return true;
    }
};