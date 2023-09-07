// DATE: 07-SEP-2023
// Question URL: https://leetcode.com/problems/reverse-linked-list-ii/

// Question: 92. Reverse Linked List II
// Description: Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
// Approach: 1. Get references to nodes at positions left and right.
//           2. Then perform reverse of linked list for these nodes.
//           3. Merge the nodes into the chain again by handling necessary edge cases.

void rev(ListNode *start, ListNode *end){

    ListNode* t1=start, *t2=start->next, *temp;
    while(t2!=end){
        temp=t2->next;
        t2->next=t1;
        t1=t2;
        t2=temp;
    }
    t2->next=t1;

}

class Solution {
public:
    ListNode* reverseBetween(ListNode* A, int B, int C) {
        if(A==NULL||A->next==NULL||B==C) return A;

    int p = 1;
    ListNode *temp=A, *start=NULL, *end=NULL, *p1=NULL, *p2=NULL;
    
    while(temp!=NULL){
        if(p==B) start=temp;
        if(p==C) end=temp, p2=temp->next;
        p++;
        if(start==NULL) p1=temp;
        temp=temp->next;
    }

    rev(start, end);
    
    if(p1!=NULL) p1->next=end;
    start->next=p2;
    
    if(B==1) A=end;
    
    return A;
    }
};