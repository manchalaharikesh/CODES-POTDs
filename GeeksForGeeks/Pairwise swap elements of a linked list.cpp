// DATE: 07-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
// Question: Pairwise swap elements of a linked list
// Description: For a given linked list swap the elements of the linked list as pairs.
// Approach: 1. Brute Force (Code-Self Explanatory).

class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        Node *new_head = NULL, *tail, *p1, *p2, *temp;
        
        if(head == NULL || head->next == NULL) return head;
        
        p1 = head;
        p2 = p1->next;
        
        while(p2 != NULL){
            if(new_head == NULL){
                temp = p2->next;
                new_head = p2;
                new_head->next = p1;
            }
            else{
                tail->next = p2;
                temp = p2->next;
                p2->next = p1;
            }
            tail = p1;
            p1 = temp;
            p2 = p1 != NULL ? p1->next : NULL;
        }
        
        if(p1 != NULL){
            tail->next = p1;
            tail = tail->next;
        }
        tail->next = NULL;
        
        return new_head;
    }
};