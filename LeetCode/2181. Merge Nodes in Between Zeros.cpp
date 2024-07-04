// DATE: 04-JUL-2024
// Question URL: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

// Question: 2181. Merge Nodes in Between Zeros
// Description: You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

//              For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

//              Return the head of the modified linked list.
// Approach: 1. Use the existing linked list to avoid additional memory usage. 
//              For each sum calculated, place the result in the most recent preceding node with a value of 0, and then link it to the next node with a value of 0. 
//              Refer to the provided code and dry run it for better understanding.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *nh = head, *t = head, *prev;
        int sum = 0;

        head = head->next;

        while(head != NULL){
            if(head->val != 0){
                sum += head->val;
            }
            else{
                t->val = sum;
                t->next = head;
                prev = t;
                t = head;
                sum = 0;
            }

            head = head->next;
        }

        t = prev;
        t->next = NULL;

        return nh;
    }
};