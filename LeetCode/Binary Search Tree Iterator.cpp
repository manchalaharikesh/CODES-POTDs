// DATE: 20-AUG-2023
// Question URL: https://leetcode.com/problems/binary-search-tree-iterator/

// Question: 173. Binary Search Tree Iterator
// Description: Complete the implementation of BSTIterator class which has methods next() and hasNext() which completes the inorder traversal of given tree.
// Approach: 1. Push all the root->left elements into the stack.
//           2. For every next() repeat step-1 on st.top()->right.

class BSTIterator {
public:
    stack<TreeNode*> st;

    void pushRight(TreeNode* node){
        while(node){
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushRight(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushRight(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};