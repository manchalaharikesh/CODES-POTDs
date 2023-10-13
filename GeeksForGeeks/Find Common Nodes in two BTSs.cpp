// DATE: 14-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1
// Question: Find Common Nodes in two BSTs
// Description: Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

//              Note: Return the common nodes in sorted order.
// Approach: 1. Traverse in first tree and store nodes in a set and do inorder traversal for second tree and if node exists in set push to vector.

class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> ans;
        set<int> s;
        
        initSet(root1, s);
        solve(root2, s, ans);
        
        return ans;
    }
    
    void initSet(Node* root, set<int>& s){
        if(root == NULL) return;
        
        s.insert(root->data);
        initSet(root->left, s);
        initSet(root->right, s);
    }
    
    void solve(Node* root, set<int>& s, vector<int>& ans){
        if(root == NULL) return;
        
        solve(root->left, s, ans);
        if(s.find(root->data) != s.end()) ans.push_back(root->data);
        solve(root->right, s, ans);
    }
};