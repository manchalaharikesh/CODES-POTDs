// DATE: 12-DEC-2023
// Question URL: https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1
// Question: Gold Mine Problem
// Description: Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

//              to the cell diagonally up towards the right 
//              to the right
//              to the cell diagonally down towards the right
//              Find out maximum amount of gold which he can collect until he can no longer move.
// Approach: 1. As a DP solution at each stage of dp[i][j] store the M[i][j] + max(dp[i-1][j+1], dp[i][j+1], dp[i+1][j+1]) for all valid i, j.

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int temp = 0, ans = 0;
        
        for(int j = m-1; j >= 0; j--){
            for(int i = 0; i < n; i++){
                temp = 0;
                // diagonally upward right
                if(i-1 >= 0 && j+1 < m) temp = max(temp, dp[i-1][j+1]);
                // right
                if(j+1 < m) temp = max(temp, dp[i][j+1]);
                // diagonally downward right
                if(i+1 < n && j+1 < m) temp = max(temp, dp[i+1][j+1]);
                
                dp[i][j] = M[i][j] + temp;
                ans = max(dp[i][j], ans);
            }
        }
        
        return ans;
    }
};