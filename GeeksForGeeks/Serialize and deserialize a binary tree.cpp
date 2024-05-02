// DATE: 02-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
// Question: Serialize and deserialize a binary tree
// Description: Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

//              serialize() : stores the tree into an array a and returns the array.
//              deSerialize() : deserializes the array to the tree and returns the root of the tree.
//              Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).
// Approach: 1. In serialize store the elements in level order wise into the array. In deSerialize for 0 element its childs are 1, 2; for 1 its childs are 3, 4; .. so on.

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        int d = 0;
        queue<Node*> q;
        vector<int> v;
        
        q.push(root);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr != NULL) v.push_back(curr->data);
            else v.push_back(-1);
            
            if(curr != NULL){
                if(curr->left != NULL) q.push(curr->left);
                else q.push(NULL);
                if(curr->right != NULL) q.push(curr->right);
                else q.push(NULL);
            }
        }

        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        Node *root = NULL, *left = NULL, *right = NULL;
        queue<Node*> q;
        int idx = 0;
        
        root = new Node(A[0]);
        root->left = NULL;
        root->right = NULL;
        q.push(root);
        
        while(!q.empty()){
            Node* p = q.front();
            q.pop();
            
            if(A[idx+1] > 0){
                left = new Node(A[idx+1]);
                left->left = NULL;
                left->right = NULL;
                p->left = left;
                q.push(left);
            }
            if(A[idx+2] > 0){
                right = new Node(A[idx+2]);
                right->left = NULL;
                right->right = NULL;
                p->right = right;
                q.push(right);
            }
            
            idx += 2;
        }
        
        return root;
    }

};