// DATE: 22-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

// Question: Paths from root with a specified sum
// Description: Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path may not end on a leaf node.
// Approach: 1. Perform tree traversal by maintaining a sum of elements that were added to vector v. Then if sum = 0 append vector v to answer.

class Solution
{
    public:
    void solve(Node* root, int sum, vector<vector<int>>& ans, vector<int>& v){
        if(root == NULL) return ;
        
        sum -= root->key;
        v.push_back(root->key);
        
        if(sum == 0){
            vector<int> temp = v;
            ans.push_back(temp);
        }
        
        solve(root->left, sum, ans, v);
        solve(root->right, sum, ans, v);
        
        sum += root->key;
        v.pop_back();
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> v;
        
        solve(root, sum, ans, v);
        
        return ans;
    }
};