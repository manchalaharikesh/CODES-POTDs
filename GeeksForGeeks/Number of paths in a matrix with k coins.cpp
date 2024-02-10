// DATE: 10-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

// Question: Number of paths in a matrix with k coins
// Description: Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).
// Approach: 1. Backtracking with DP.

class Solution {
public:
    long long solve(int i, int j, int n, int k, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp){
        if(i >= n || j >= n || k <= 0) return 0;
        if(i == n-1 && j == n-1) return k == arr[i][j];
        if(dp[i][j][k] != -1) return dp[i][j][k];

        return dp[i][j][k] = solve(i+1, j, n, k-arr[i][j], arr, dp) + solve(i, j+1, n, k-arr[i][j], arr, dp);
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        
        return solve(0, 0, n, k, arr, dp);
    }
};