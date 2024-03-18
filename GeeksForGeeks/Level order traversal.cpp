// DATE: 18-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/level-order-traversal/1
// Question: Level order traversal
// Description: Given a root of a binary tree with n nodes, find its level order traversal.
//              Level order traversal of a tree is breadth-first traversal for the tree.
// Approach: 1. Code is Self-Explanatory.

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        queue<Node*> q;
      
        q.push(root);
      
        while(!q.empty()){
            ans.push_back(q.front()->data);
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
        }
        
        return ans;
    }
};