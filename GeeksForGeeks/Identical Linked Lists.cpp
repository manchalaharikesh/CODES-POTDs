// DATE: 29-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/identical-linked-lists/1
// Question: Identical Linked Lists
// Description: Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
//              Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false.
// Approach: 1. Code - Self Explanatory.

/*
Structure of the node of the linked list is as
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to check whether two linked lists are identical or not.
bool areIdentical(struct Node *head1, struct Node *head2) {
    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return head1 == head2 && head1 == NULL ? true : false;
}