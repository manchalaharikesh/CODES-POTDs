// DATE: 30-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
// Question: Add two numbers represented by linked lists
// Description: Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

//              For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

//              Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* remove_trail_zeros(struct Node *head){
        while(head != NULL){
            if(head->data != 0) return head;
            head = head->next;
        }
        
        return NULL;
    }
    
    struct Node* reverse(struct Node* head, int& l){
        struct Node *temp = head, *prev = NULL;
        
        while(head != NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
            l++;
        }
        
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        int c = 0, a = 0, b = 0, l1 = 0, l2 = 0;
        struct Node *temp1, *temp2, *prev;
        
        num1 = remove_trail_zeros(num1);
        num2 = remove_trail_zeros(num2);
        num1 = reverse(num1, l1);
        num2 = reverse(num2, l2);
        
        temp1 = num1;
        temp2 = num2;
        
        if(temp1 == NULL && temp2 == NULL) return new Node(0);
        
        if(l1 < l2){
            temp1 = num2;
            temp2 = num1;
        }
        
        while(temp1 != NULL || temp2 != NULL){
            a = temp1 != NULL ? temp1->data : 0;
            b = temp2 != NULL ? temp2->data : 0;
            
            temp1->data = (a + b + c) % 10;
            c = (a + b + c) / 10;
            
            prev = temp1;
            temp1 = temp1 != NULL ? temp1->next : NULL;
            temp2 = temp2 != NULL ? temp2->next : NULL;
        }
        
        if(c != 0) prev->next = new Node(c);
        
        return reverse(l1 >= l2 ? num1 : num2, l1);
    }
};