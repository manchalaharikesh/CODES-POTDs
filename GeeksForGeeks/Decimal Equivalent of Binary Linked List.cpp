// DATE: 03-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1
// Question: Decimal Equivalent of Binary Linked List
// Description: Given a singly linked list of length n. The link list represents a binary number, ie- it contains only 0s and 1s. Find its decimal equivalent.
//              The significance of the bits decreases with the increasing index in the linked list.
//              An empty linked list is considered to represent the decimal value 0. 

//              Since the answer can be very large, answer modulo 109+7 should be printed.
// Approach: 1. Code - Self Explanatory.

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

class Solution
{
    public:
        Node* reverse(Node* head){
            Node *prev = NULL, *temp = head->next;
            
            while(head != NULL){
                temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
            }
            
            return prev;
        }
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           if(head == NULL) return 0;
           
           long long unsigned int ans = 0, mul = 1;
           head = reverse(head);
           
           while(head != NULL){
               if(head->data) ans = (ans + mul) % 1000000007;
               mul = (mul*2) % 1000000007;
               head = head->next;
           }
           
           return ans;
        }
};