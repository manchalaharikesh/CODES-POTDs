// DATE: 15-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
// Question: Normal BST to Balanced BST
// Description: For a given binary search tree, convert it into a balanced binary search tree with minimum height possible. Return any possible answer.
// Approach: 1. Store inorder traversal of nodes in a vector. Now build the tree using the merge sort logic to conquer in middle to get BST with minimum height.

class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
    	vector<Node*> nodes;
    	int p1, p2;
    	Node* ans = NULL;
    	
    	inorder(root, nodes);
    	
    	for(int i = 0; i < nodes.size(); i++){
    	    nodes[i]->left = NULL;
    	    nodes[i]->right = NULL;
    	}
    	
    	ans = createTree(nodes, 0, nodes.size()-1);
    	
    	return ans;
    }
    
    void inorder(Node* root, vector<Node*>& nodes){
        if(root == NULL) return;
        
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
    
    Node* createTree(vector<Node*>& nodes, int low, int high){
        if(low <= high){
            int mid = low + (high - low)/2;
            Node* root = nodes[mid];
            
            root->left = createTree(nodes, low, mid-1);
            root->right = createTree(nodes, mid+1, high);
            
            return root;
        }
        
        return NULL;
    }
    
};