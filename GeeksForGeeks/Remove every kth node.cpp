// DATE: 29-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

// Question: Remove every kth node
// Description: Given a singly linked list having n nodes, your task is to remove every kth node from the linked list. 
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(K == 1) return NULL;
        int c = 1;
        Node *temp = head, *new_head = NULL, *new_tail = NULL;
        
        while(temp != NULL){
            if(c != K){
                if(new_head == NULL) new_head  = new_tail = temp;
                else{
                    new_tail->next = temp;
                    new_tail = temp;
                }
            }
            else{
                c = 0;
            }
            temp = temp->next;
            c++;
        }
        if(new_tail != NULL) new_tail->next = NULL;
        
        return new_head;
    }
};