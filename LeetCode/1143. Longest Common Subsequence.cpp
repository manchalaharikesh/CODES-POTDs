// DATE: 25-JAN-2024
// Question URL: https://leetcode.com/problems/longest-common-subsequence/description/

// Question: 1143. Longest Common Subsequence
// Description: Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

//              A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

//              For example, "ace" is a subsequence of "abcde".
//              A common subsequence of two strings is a subsequence that is common to both strings.
// Approach: 1. DP[i][j] contains the maximum possible longest-common-subsequence for 0 to ith chars in text1, 0 to jth chars in text2. Below code is self-explanatory and is memory optimized DP solution.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(2, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(text1[i] == text2[j]){
                    dp[i%2][j] = (i != 0 && j != 0) ? dp[(i-1)%2][j-1] + 1 : 1;
                }
                else{
                    dp[i%2][j] = i == 0 && j == 0 ? 0 : i == 0 ? dp[i%2][j-1] : j == 0 ? dp[(i-1)%2][j] : max({dp[(i-1)%2][j], dp[i%2][j-1], dp[(i-1)%2][j-1]});
                }
            }
        }

        return dp[(m-1)%2][n-1];
    }
};