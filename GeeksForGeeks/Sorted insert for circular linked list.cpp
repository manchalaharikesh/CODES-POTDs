// DATE: 05-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

// Question: Sorted insert for circular linked list
// Description: Given a sorted circular linked list of length n, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.
// Approach: 1. Brute Force.

/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        Node *temp = head, *tail, *prev;
        Node *nn = new Node(data);
        nn->next = nn;
        
        if(head == NULL) return nn;
        
        while(temp->next != head) temp = temp->next;
        tail = temp;
        temp = head;
        
        while(data > temp->data){
            if(temp == tail){
                temp = NULL;
                break; 
            }
            prev = temp;
            temp = temp->next;
        }
        
        if(head == tail){
            if(data < head->data){
                nn->next = head;
                head->next = nn;
                head = nn;
            }
            else{
                tail->next = nn;
                nn->next = head;
            }
        }
        else if(temp == NULL){
            tail->next = nn;
            nn->next = head;
        }
        else if(temp == head){
            nn->next = head;
            head = nn;
            tail->next = nn;
        }
        else{
            nn->next = temp;
            prev->next = nn;
        }
        
        return head;
    }
};