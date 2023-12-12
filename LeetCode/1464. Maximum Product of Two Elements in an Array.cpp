// DATE: 12-DEC-2023
// Question URL: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

// Question: 1464. Maximum Product of Two Elements in an Array
// Description: Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
// Approach: 1. Decrement all by 1 and sort them for maximum numbers.
//           2. Decrement all by 1 and find the 2 maximum numbers.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) nums[i]--;

        sort(nums.begin(), nums.end());

        return nums[n - 1] * nums[n - 2];
    }
};