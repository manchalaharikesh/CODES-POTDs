// DATE: 13-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1
// Question: Insertion Sort for Singly Linked List
// Description: Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.
// Approach: 1. Brute Force / Code Self Explanatory.

class Solution
{
    public:
    
    Node* insert(struct Node* head, struct Node* node){
        if(head == NULL) return node;
        
        if(head->data >= node->data){
            node->next = head;
            return node;
        }
        else head->next = insert(head->next, node);
        return head;
    }
    
    Node* insertionSort(struct Node* head_ref)
    {
        struct Node *head = NULL, *temp = NULL;
        
        while(head_ref != NULL){
            temp = head_ref;
            head_ref = head_ref->next;
            temp->next = NULL;
            head = insert(head, temp);
        }
        
        return head;
    }
    
};