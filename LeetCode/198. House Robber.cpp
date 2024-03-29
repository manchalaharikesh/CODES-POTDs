// DATE: 21-JAN-2024
// Question URL: https://leetcode.com/problems/house-robber/description/

// Question: 198. House Robber
// Description: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

//              Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Approach: 1. dp[i] = max(dp[i-2] + nums[i], dp[i-1]) because if we want to select ith state (nums[i]) we can't select (i-1)th state and at dp[i] we have the maximum loot that can be made from 0 to ith index.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        if(n <= 2) return *max_element(nums.begin(), nums.end());

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    } 
};