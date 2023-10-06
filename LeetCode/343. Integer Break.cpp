// DATE: 06-OCT-2023
// Question URL: https://leetcode.com/problems/integer-break/

// Question: 343. Integer Break
// Description: Given an integer n we need to split n into k integers such that the product of these k integers is maximum where k >= 2.
// Approach: 1. By Dymanic Programming at dp[i] for i be the integer to be split store the maximum possible product value for integer i by making splits k (k >= 2).

class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        vector<int> dp(n+1, 0);

        dp[1] = 1;

        for(int i = 1; i <= n/2; i++){
            ans = max(ans, i*solve(i, n-i, dp));
        }

        return ans;
    }

    int solve(int i, int target, vector<int>& dp){
        if(dp[target] != 0) return dp[target];
        int temp = 0;
        while(i <= target/2){
            temp = max({temp, target, i*solve(i, target - i, dp)});
            i++;
        }
        dp[target] = temp;
        return temp;
    }
};