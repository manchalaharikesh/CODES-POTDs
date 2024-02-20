// DATE: 20-FEB-2024
// Question URL: https://leetcode.com/problems/missing-number/description/

// Question: 268. Missing Number
// Description: Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
// Approach: 1. Sum of natural numbers is n*(n+1)/2. Subtract each element of nums from sum to get missing number.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = nums.size() * (nums.size() + 1) / 2;

        for(int i = 0; i < nums.size(); i++){
            total -= nums[i];
        }

        return total;
    }
};