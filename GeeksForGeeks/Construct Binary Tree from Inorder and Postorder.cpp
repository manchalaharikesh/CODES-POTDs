// DATE: 04-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
// Question: Construct Binary Tree from Inorder and Postorder
// Description: Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively. The task is to construct a binary tree from these traversals.

//              Driver code will print the preorder traversal of the constructed tree.
// Approach: 1. In inorder for a parent all the elements to its left are of its leftSubTree and all the elements to its right are of its rightSubTree.
//              And in postorder from above every left and right subtree traversal is followed by the parent element.
//              Thus we find the root from postorder and find its left and right subtree elements in inorder traversal.
//              For other detailing try understanding the code 😔.

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node* build(int in[], map<int, int>& m, int parent, int low, int high){
        if(low >= high) return NULL;
        
        int idx = -1, left_child = -1, left_idx_max = -1, right_child = -1, right_idx_max = -1;
        bool inLeft = true;
        Node* root = new Node(parent);
        
        for(int i = low; i < high; i++){
            if(in[i] == parent){
                inLeft = false;
                idx = i;
            }
            else if(inLeft){
                if(m[in[i]] > left_idx_max){
                    left_idx_max = m[in[i]];
                    left_child = in[i];
                }
            }
            else{
                if(m[in[i]] > right_idx_max){
                    right_idx_max  = m[in[i]];
                    right_child = in[i];
                }
            }
        }
        
        root->left = build(in, m, left_child, low, idx);
        root->right = build(in, m, right_child, idx+1, high);
        
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        map<int, int> m;
        
        for(int i = 0; i < n; i++){
            m[post[i]] = i;
        }
        
        Node* root = build(in, m, post[n-1], 0, n);
        
        return root;
    }
};