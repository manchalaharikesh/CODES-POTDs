// DATE: 28-SEP-2023
// Question URL: https://leetcode.com/problems/sort-array-by-parity/

// Question: 905. Sort Array By Parity
// Description: Given an array arr convert it in such a way that all even numbers occur before the odd numbers and preserve their order.
// Approach: 1. Two pointer concept where p1 = -1 and p2 = 0 when nums[p2] is odd increment p2 but when nums[p2] is even swap nums[++p1] and nums[p2].

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p1 = -1, p2 = 0;

        while(p2 < nums.size()){
            if((nums[p2] & 1) == 0){
                swap(nums, p1, p2);
            }
            p2++;
        }

        return nums;
    }

    void swap(vector<int>& nums, int p1, int p2){
        int temp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = temp;
    }
};