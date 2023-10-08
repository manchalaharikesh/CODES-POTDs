// DATE: 08-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1
// Question: Insert in a Sorted List
// Description: For a given sorted linked list and a data integer add the data integer such that the list is stil sorted and return the head of linked list after modifying it. And do not use extra memory except for the new node to be created.
// Approach: 1. Code - Self Explanatory.

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node *nn = new Node(data), *temp = head;
        
        if(data <= head->data){
            nn->next = head;
            head = nn;
        }
        else{
            while(temp->next != NULL && temp->next->data < data){
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;
        }
        
        return head;
    }
};