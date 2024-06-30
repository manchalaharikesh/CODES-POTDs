// DATE: 30-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1
// Question: Delete node in Doubly Linked List
// Description: Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.
// Approach: 1. Code is Self-Explanatory.

/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        Node *temp = head, *prev = NULL;
        
        while(x > 1){
            x--;
            prev = temp;
            temp = temp->next;
        }
        
        if(temp->next != NULL) temp->next->prev = prev;
        
        if(prev != NULL) prev->next = temp->next;
        else head = temp->next;
        
        return head;
    }
};