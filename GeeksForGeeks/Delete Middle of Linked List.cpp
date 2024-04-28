// DATE: 28-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
// Question: Delete Middle of Linked List
// Description: Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
//              If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
//              If the input linked list has single node, then it should return NULL.
// Approach: 1. Slow and Fast pointer approach.

class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        if(head == NULL || head->next == NULL) return NULL;
        
        Node *slow = head, *fast = head->next;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};