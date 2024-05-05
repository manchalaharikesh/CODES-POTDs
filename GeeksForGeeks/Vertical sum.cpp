// DATE: 05-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/vertical-sum/1
// Question: Vertical sum
// Description: Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.
// Approach: 1. For root node let its vertical level be 0 then its left child has vertical level of -1 and right child has vertical level of +1.
//              Repeat it for all nodes such that for a node with vertical level as 'l', its left child has level of 'l-1' and right child has level of 'l+1'
//              And also add the node data to its corresponding level in the map. As map is sorted by key values in cpp we can directly iterate it and store values into vector.

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    void dfs(Node* root, map<int, int>& m, int l){
        if(root == NULL) return ;
        
        if(m.find(l) == m.end()){
            m[l] = root->data;
        }
        else{
            m[l] += root->data;
        }
        
        dfs(root->left, m, l-1);
        dfs(root->right, m, l+1);
    }
    vector <int> verticalSum(Node *root) {
        map<int, int> m;
        vector<int> ans;
        
        dfs(root, m, 0);
        
        for(auto it = m.begin(); it != m.end(); it++){
            ans.push_back(it->second);
        }
        
        return ans;
    }
};