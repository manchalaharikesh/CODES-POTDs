// DATE: 07-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1
// Question: Ancestors in Binary Tree
// Description: Given a Binary Tree and an integer target. Find all the ancestors of the given target.

//              Note:

//              The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y. Consider multiple levels of ancestors to solve this problem.
//              In case there are no ancestors available, return an empty list.
// Approach: 1. As we need to list the ansectors of a target node we can simply do it by a dfs type of tree traversal by storing (visited) and popping (back tracked) nodes while traversing.
//              We can do it as a way of using any tree traversal algorithm.
//              The current solution uses a preorder traversal where we use a vector ans to store and pop nodes, a boolean found to prevent further recursive iterations and prevent popping nodes.
//              Here we check for current root node to be the target if not we push it into the vector with the hope that it will be the ansector of the target and continue the recursive traversal.
//              If we can't traverse further and didn't find the target we need to back track and also need to pop the node as it can't be the ansector.
//              When we find the target we stop any further traversal and any further back traverse and popping of nodes as until the target node the nodes in vector ans are all required ansectors.
//              Now as we need to return answer in increasing order of hierarchy of ansectors we need to reverse the vector and return it.
//              For better understanding please refer to code and Dry Run it.

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
  public:
    void preorder(Node* root, int target, vector<int>& ans, bool& found){
        if(root == NULL) return ;
        
        if(root->data == target){
            found = true;
            return ;
        }
        ans.push_back(root->data);
        preorder(root->left, target, ans, found);
        if(!found) preorder(root->right, target, ans, found);
        if(!found) ans.pop_back();
    }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> ans;
        bool found = false;
        
        preorder(root, target, ans, found);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};