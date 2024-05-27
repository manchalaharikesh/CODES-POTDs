// DATE: 27-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
// Question: Longest subsequence-1
// Description: Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.
// Approach: 1. The current solution is a DP based approach.
//              For every element in a, in the dp array we store the length of the maximum possible subsequence possible towards its right.
//              For any element at index i it may have many possibilities for its neighbor elements with absolute diff 1.
//              Thus for any element at index i we choose the element that might give longest subsequence and update it at dp[i] = dp[max subsequence at j] + 1 (j is in [i+1, n)).
//              The final answer is the maximum length stored in the dp array.

class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        vector<int> dp(n, 0);
        int c = 0;
        
        dp[n-1] = 1;
        
        for(int i = n-2; i >= 0; i--){
            c = 0;
            for(int j = i; j < n; j++){
                if(abs(a[i] - a[j]) == 1){
                    c = max(c, dp[j]);
                }
            }
            dp[i] = c+1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};