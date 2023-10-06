// DATE: 06-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1

// Question: Reverse alternate nodes in Linked List
// Description: Extract alternate nodes from second position and reverse them and add it to the end of original list. 
// Approach: 1. Brute Force.

class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        Node *head2 = NULL, *temp1 = NULL, *temp2 = NULL, *p1 = odd, *p2 = odd->next;
        
        if(odd == NULL || odd->next == NULL || odd->next->next == NULL) return ;
        
        while(p2 != NULL){
            if(temp1 == NULL){
                temp1 = p1;
                temp2 = p2;
                head2 = p2;
            }
            else{
                temp1->next = p1;
                temp1 = p1;
                temp2->next = p2;
                temp2 = p2;
            }
            
            p1 = p2->next;
            p2 = p1 != NULL ? p1->next : NULL;
        }
        
        if(p1 != NULL){
            temp1->next = p1;
            temp1 = p1;
        }
        
        temp2->next = NULL;
        temp1->next = NULL;

        temp1->next = reverseLL(head2);
    }
    
    Node* reverseLL(Node* head){
        Node *newHead = NULL, *temp = NULL;
        
        while(head != NULL){
            if(newHead == NULL){
                newHead = head;
                head = head->next;
                newHead->next = NULL;
            }
            else{
                temp = head->next;
                head->next = newHead;
                newHead = head;
                head = temp;
            }
        }
        
        return newHead;
    }
};