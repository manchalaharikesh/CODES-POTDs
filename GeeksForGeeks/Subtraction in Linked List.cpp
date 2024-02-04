// DATE: 04-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1
// Question: Subtraction in Linked List
// Description: You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
public:
    Node* removeZeros(Node* head){
        while(head != NULL){
            if(head->data != 0) return head;
            head = head->next;
        }
        
        return head;
    }
    
    int getLength(Node* head){
        int l = 0;
        
        while(head != NULL){
            l++;
            head = head->next;
        }
        
        return l;
    }
    Node* getGreaterNumber(Node* head1, Node* head2){
        Node *temp1 = head1, *temp2 = head2;
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data > temp2->data) return head1;
            else if(temp1->data < temp2->data) return head2;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        if(temp1 == NULL && temp2 == NULL) return NULL;
        
        return temp1 == NULL ? head2 : head1;
    }
    
    Node* reverseList(Node* head){
        Node *prev = NULL, *temp = head->next;
        
        while(head != NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
    Node* subtract(Node* greater, Node* smaller){
        bool takenCarry = false;
        Node *temp1 = greater, *temp2 = smaller;
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data < temp2->data){
                if(temp1->data == 0 && !takenCarry) temp1->data = 10 - temp2->data;
                else if(temp1->data == 0 && takenCarry) temp1->data = 9 - temp2->data;
                else if(temp1->data != 0 && !takenCarry) temp1->data = 10+(temp1->data) - temp2->data;
                else if(temp1->data != 0 && takenCarry) temp1->data = 10+(temp1->data - 1) - temp2->data;
                
                takenCarry = true;
            }
            else if(temp1->data == temp2->data){
                if(temp1->data == 0 && !takenCarry) temp1->data = 0;
                else if(temp1->data == 0 && takenCarry) temp1->data = 9;
                else if(temp1->data != 0 && !takenCarry) temp1->data = 0;
                else if(temp1->data != 0 && takenCarry) temp1->data = 10+(temp1->data - 1) - temp2->data;
            }
            else if(temp1->data > temp2->data){
                if(!takenCarry) temp1->data = temp1->data - temp2->data;
                else if(takenCarry) temp1->data = temp1->data - 1 - temp2->data;
                takenCarry = false;
            }
            
            // cout << temp1->data << " " << temp2->data << "\n";
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        if(temp1 == NULL && temp2 == NULL) return greater;
        else if(takenCarry){
            while(temp1->data == 0){
                temp1->data = 9;
                temp1 = temp1->next;
            }
            
            temp1->data -= 1;
        }
        
        return greater;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        int l1, l2;
        Node *greater, *smaller, *ans;
        
        head1 = removeZeros(head1);
        head2 = removeZeros(head2);
        
        if(head1 == NULL && head2 == NULL) return new Node(0);
        else if(head1 == NULL || head2 == NULL) return head1 != NULL ? head1 : head2;
        
        l1 = getLength(head1);
        l2 = getLength(head2);
        
        greater = l1 > l2 ? head1 : l1 < l2 ? head2 : getGreaterNumber(head1, head2);
        
        if(greater == NULL) return new Node(0);
        smaller = greater == head1 ? head2 : head1;
        
        greater = reverseList(greater);
        smaller = reverseList(smaller);
        
        ans = subtract(greater, smaller);
        
        ans = reverseList(ans);
        ans = removeZeros(ans);
        
        return ans;
    }
};