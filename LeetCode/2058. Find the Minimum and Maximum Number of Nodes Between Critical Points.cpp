// DATE: 05-JUL-2024
// Question URL: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

// Question: 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Description: A critical point in a linked list is defined as either a local maxima or a local minima.

//              A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

//              A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

//              Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

//              Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
// Approach: 1. Brute Force - Code is Self-Explanatory. Dry Run code for better understanding.

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int f = 0, l = 0, _min = INT_MAX, _max = 0, i = 1;
        vector<int> ans;

        ListNode *prev = head;
        head = head->next;

        while(head->next != NULL){
            // local maximum
            if(prev->val < head->val && head->val > head->next->val){
                if(f == 0) f = i;
                else _min = min(_min, i - l);
                l = i;
            }
            // local minima
            else if(prev->val > head->val && head->val < head->next->val){
                if(f == 0) f = i;
                else _min = min(_min, i - l);
                l = i;
            }

            i++;
            prev = head;
            head = head->next;
        }

        if(_min != INT_MAX){
            _max = l - f;
            ans.push_back(_min);
            ans.push_back(_max);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }

        return ans;
    }
};