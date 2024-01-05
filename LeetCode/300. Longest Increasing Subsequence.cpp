// DATE: 05-JAN-2024
// Question URL: https://leetcode.com/problems/longest-increasing-subsequence/description/

// Question: 300. Longest Increasing Subsequence
// Description: Given an integer array nums, return the length of the longest strictly increasing subsequence.
// Approach: 1. Generate all increasing subsequences and get the sequence of max length .
//           2. Have a dp array where we store the length of subsequence possible from 0th index to ith index.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            int _max = INT_MIN;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[j] > _max){
                    _max = dp[j];
                }
            }

            if(_max > INT_MIN){
                dp[i] = _max + 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};