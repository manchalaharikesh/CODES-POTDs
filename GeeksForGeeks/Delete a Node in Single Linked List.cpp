// DATE: 30-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1
// Question: Delete a Node in Single Linked List
// Description: For a given LL and number of node remove it and return the linked list.
// Approach: 1. Maintain prev and temp (curr), have a counter c, and if c == x make prev point to curr->next.

Node* deleteNode(Node *head,int x)
{
    Node *temp = head, *prev = NULL;
    int c = 1;
    
    if(x == 1) return head->next;
    
    while(temp != NULL){
        if(c == x){
            prev->next = temp->next;
            break;
        }
        prev = temp;
        temp = temp->next;
        c++;
    }
    
    return head;
}