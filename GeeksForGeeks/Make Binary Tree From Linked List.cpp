// DATE: 01-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/make-binary-tree/1
// Question: Make Binary Tree From Linked List
// Description: Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree and print the level order traversal of the Binary tree. 
//              Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.
// Approach: 1. The given linked list is also the level order traversal of elements of the complete binary tree. We need to construct back the complete binary tree from this linked list.
//              To do so, we initially take the head of the linked list as root node of tree, then the next two elements of linked list needs to be the childs of the root, and for each child the next following two nodes becomes child and so on.
//              Thus we insert the head node into the queue and move forward in linked list and in the recursive call for every element in front in queue we get its left and right child from linked list, and also push left and right childs to the end of the queue.
//              Then parallelly linked list is also moved forward by two positions each time as we convered childs for current root. Thus through the recursive calls we can build the whole tree by parallely moving and pushing nodes from linked list into the queue.
//              For better understanding refer to code.

/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void solve(Node *head, queue<TreeNode*>& q){
    if(head == NULL) return ;
    
    TreeNode *root = q.front();
    q.pop();
    
    TreeNode *left = new TreeNode(head->data);
    head = head->next;
    
    TreeNode *right = head != NULL ? new TreeNode(head->data) : NULL;
    head = head != NULL ? head->next : NULL;
    
    root->left = left;
    root->right = right;
    
    q.push(left);
    q.push(right);
    
    solve(head, q);
}

void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> q;
    
    root = new TreeNode(head->data);
    q.push(root);
    head = head->next;
    
    solve(head, q);
}
