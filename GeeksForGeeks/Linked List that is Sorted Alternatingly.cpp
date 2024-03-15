// DATE: 15-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
// Question: Linked List that is Sorted Alternatingly
// Description: You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.
// Approach: 1. Get the alternating nodes into two seperate lists both in ascending order. Then iterate both in parallel and pick nodes in ascending order.

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
        Node *ascTail = NULL, *desHead = NULL, *temp = *head, *n = (*head)->next, *new_head = NULL;
        bool asc = true;

        while(temp != NULL){
            if(asc){
                if(ascTail == NULL) ascTail = temp;
                else{
                    n = temp->next;
                    ascTail->next = temp;
                    ascTail = temp;
                }
            }
            else{
                n = temp->next;
                temp->next = desHead;
                desHead = temp;
            }
            temp = n;
            asc = !asc;
        }
        
        ascTail->next = NULL;
        ascTail = NULL;
        
        while(*head != NULL && desHead != NULL){
            if((*head)->data < desHead->data){
                if(new_head == NULL){
                     new_head = *head;
                     temp = *head;
                }
                else{
                    temp->next = *head;
                    temp = *head;
                }
                *head = (*head)->next;
            }
            else{
                if(new_head == NULL){
                     new_head = desHead;
                     temp = desHead;
                }
                else{
                    temp->next = desHead;
                    temp = desHead;
                }
                desHead = desHead->next;
            }
        }
        
        if(*head != NULL && temp != NULL) temp->next = *head;
        else if(temp != NULL) temp->next = desHead;
        
        if(new_head != NULL) *head = new_head;
    }
};