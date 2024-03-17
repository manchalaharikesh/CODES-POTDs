// DATE: 17-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1
// Question: Count Pairs whose sum is equal to X
// Description: Given two linked list head1 and head2 with distinct elements, determine the count of all distinct pairs from both lists whose sum is equal to the given value x.

//              Note: A valid pair would be in the form (x, y) where x is from first linked list and y is from second linked list.
// Approach: 1. Store head2 elements in map. For every element of x-head1 if it exists in map increment ans.

/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_map<int, int> m;
        int ans = 0;
        
        while(head2 != NULL){
            m[head2->data] = 1;
            head2 = head2->next;
        }
        
        while(head1 != NULL){
            if(m.find(x - head1->data) != m.end()){
                ans++;
            }
            
            head1 = head1->next;
        }
        
        return ans;
    }
};