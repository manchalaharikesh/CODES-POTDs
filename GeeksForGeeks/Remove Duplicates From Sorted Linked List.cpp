// DATE: 28-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

// Question: Remove Duplicates from sorted linked list.
// Description: Given a sorted linked list remove duplicate elements from it. 
// Approach: 1. Have a new head, add nodes to it if the tail value is different from curr of original LL.

Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL) return head;
    Node *new_head = NULL, *temp = NULL;
    
    while(head != NULL){
        if(new_head == NULL){
            temp = head;
            new_head = head;
        }
        else{
            if(head->data != temp->data){
                temp->next = head;
                temp = temp->next;
            }
        }
        head = head->next;
        temp->next = NULL;
    }
    
    return new_head;
}