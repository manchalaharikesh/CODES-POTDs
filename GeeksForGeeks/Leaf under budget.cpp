// DATE: 03-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/leaf-under-budget/1
// Question: Leaf under budget
// Description: For a given tree root node and budget (cost is the level of root node) find the number of leaf nodes can be visited with in budget.
// Approach: 1. Perform level order traversal (similar to BFS principle), for any leaf node seen subtract level from budget.
//           2. continue until no further traversal is possible or if budget is less than next leaf node level 
//              (as it is level order traversal for any leaf node encountered and its level is greater than budget then no further leaf node will be with in the budget).

class Solution
{
public:
    int getCount(Node *root, int k)
    {
        queue<pair<Node*, int>> q;
        int ans = 0;
        
        q.push(pair<Node*, int>(root, 1));
        
        if(root == NULL) return 0;
        
        while(!q.empty()){
            vector<int> v;
            pair<Node*, int> p = q.front();
            Node* temp = p.first;
            int level = p.second;
            
            if(level > k) break;
            
            q.pop();
            
            if(temp->left == NULL && temp->right == NULL){
                k-= level;
                ans++;
            }
            else{
                if(temp->left != NULL) q.push(pair<Node*, int>(temp->left, level+1));
                if(temp->right != NULL) q.push(pair<Node*, int>(temp->right, level+1));
            }
        }
        
        return ans;
    }
};