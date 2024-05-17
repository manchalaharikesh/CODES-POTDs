// DATE: 17-MAY-2024
// Question URL: https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

// Question: 1325. Delete Leaves With a Given Value
// Description: Given a binary tree root and an integer target, delete all the leaf nodes with value target.

//              Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).
// Approach: 1. This approach includes a marker and an eraser.
//              The marker initially marks the leaf nodes with target value as negative then further for any parent node (with target as value) if its childs is either NULL or negative it means both has only target elements. Then we also mark parent as negative and it is repeated recursively.
//              The eraser deletes the subtrees with root element as negative indicating that whole subtree contains target elements only.

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
    void marker(TreeNode* root, int target){
        if(root == NULL) return ;

        marker(root->left, target);
        marker(root->right, target);

        if(root->left == NULL && root->right == NULL && root->val == target) root->val = -(root->val);
        else if(root->val == target && (root->left == NULL || root->left->val < 0) && (root->right == NULL || root->right->val < 0)){
            root->val = -(root->val);
        }
    }
    void eraser(TreeNode* root){
        if(root == NULL) return ;
        
        if(root->left != NULL && root->left->val < 0) root->left = NULL;
        else eraser(root->left);

        if(root->right != NULL && root->right->val < 0) root->right = NULL;
        else eraser(root->right);        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        marker(root, target);

        if(root->val < 0) return NULL;
        eraser(root);

        return root;
    }
};