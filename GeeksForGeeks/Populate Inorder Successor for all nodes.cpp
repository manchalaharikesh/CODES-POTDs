// DATE: 06-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
// Question: Populate Inorder Successor for all nodes
// Description: Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.
//              You do not have to return or print anything. Just make changes in the root node given to you.

//              Note: The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.
// Approach: 1. Here, every node has three pointers, left, right child pointers and a new next pointer which needs to be updated with the node address of its successor in inorder traversal.
//              Thus every node next pointer must have reference to its successor in its inorder traversal, ans for those who don't have any successor node the driver code will handle placing -1.
//              So here it is clear that we need to know the successor prior to reaching the root node in traversal to update root->next.
//              Thus, we adopt to traverse the tree in reverse of inorder i.e., explore the right subtree first, then root, then left subtree.
//              This way we have our reference to the successor nodes stored before reaching the root and can easily place root->next = successor node.
//              For better understanding please refer to code.

/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    void inorder(Node* root, Node*& pre){
        if(root == NULL) return ;
        
        inorder(root->right, pre);
        if(pre != NULL) root->next = pre;
        pre = root;
        inorder(root->left, pre);
    }
    void populateNext(Node *root) {
        Node* pre = NULL;
        
        inorder(root, pre);
    }
};