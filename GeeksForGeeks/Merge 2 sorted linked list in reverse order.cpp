// DATE: 08-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1
// Question: Merge 2 sorted linked list in reverse order
// Description: Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.
// Approach: 1. Brute Force.

class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        struct Node *p1 = node1, *p2 = node2, *head = NULL, *temp;
        
        while(p1 != NULL || p2 != NULL){
            if(p1 == NULL){
                temp = p2->next;
                p2->next = head;
                head = p2;
                p2 = temp;
            }
            else if(p2 == NULL){
                temp = p1->next;
                p1->next = head;
                head = p1;
                p1 = temp;
            }
            else{
                if(p1->data <= p2->data){
                    temp = p1->next;
                    p1->next = head;
                    head = p1;
                    p1 = temp;
                }
                else{
                    temp = p2->next;
                    p2->next = head;
                    head = p2;
                    p2 = temp;
                }
            }
        }
        
        return head;
    }  
};