// DATE: 03-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1
// Question: Remove all occurences of duplicates in a linked list
// Description: Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list.
// Approach: 1. Brute Force Code is Self-Explanatory.

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        Node *nh = NULL, *tail = NULL;
        int c;
        
        while(head != NULL){
            c = 1;
            while(head->next != NULL && head->data == head->next->data){
                head = head->next;
                c++;
            }
            
            if(c == 1){
                if(nh == NULL){ 
                    nh = head;
                    tail = head;
                }
                else{
                    tail->next = head;
                    tail = head;
                }
            }
            
            head = head->next;
        }
        
        if(tail != NULL) tail->next = NULL;
        
        return nh;
    }
};