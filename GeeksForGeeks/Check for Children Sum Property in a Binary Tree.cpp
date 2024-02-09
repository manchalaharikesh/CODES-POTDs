// DATE: 09-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/children-sum-parent/1
// Question: Check for Children Sum Property in a Binary Tree
// Description: Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

//              For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.
// Approach: 1. Brute Force Code is Self-Explanatory.

/*Complete the function below

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

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(root == NULL) return true;
        else if(root->left == NULL && root->right == NULL) return true;
        
        int l = (root->left != NULL) ? root->left->data : 0;
        int r = (root->right != NULL) ? root->right->data : 0;
        
        if(root->data != l + r) return false;
        
        if(isSumProperty(root->left) && isSumProperty(root->right)) return true;
        return false;
    }
};