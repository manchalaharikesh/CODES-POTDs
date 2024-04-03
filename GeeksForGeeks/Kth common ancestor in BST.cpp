// DATE: 03-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1
// Question: Kth common ancestor in BST
// Description: Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

//              Nodes x and y will always be present in the input of a BST, and x != y.
// Approach: 1. We find all the LCAs for both x and y and then find the kth common ansector from bottom.

class Solution
{
    public:
    void lcas(Node* root, vector<int>& lca_nodes, int x, int y){
        if(root == NULL) return;
        else if(root->data == x || root->data == y){
            lca_nodes.push_back(root->data);
            return;
        }
        
        if(x < root->data && y < root->data){
            lca_nodes.push_back(root->data);
            lcas(root->left, lca_nodes, x, y);
        }
        else if(x > root->data && y > root->data){
            lca_nodes.push_back(root->data);
            lcas(root->right, lca_nodes, x, y);
        }
        else{
            lca_nodes.push_back(root->data);
        }
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {   
        vector<int> lca_nodes;
        lcas(root, lca_nodes, x, y);
        
        reverse(lca_nodes.begin(), lca_nodes.end());
        
        return lca_nodes.size() >= k ? lca_nodes[k-1] : -1;
    }
};