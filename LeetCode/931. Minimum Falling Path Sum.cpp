// DATE: 19-JAN-2024
// Question URL: https://leetcode.com/problems/minimum-falling-path-sum/description/

// Question: 931. Minimum Falling Path Sum
// Description: Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

//              A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
// Approach: 1. As a dp appraoch at dp[i][j] we have the min possible cost from all possible entry points to it.

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                dp[i+1][j] = min(dp[i][j] + matrix[i+1][j], dp[i+1][j]);
                if(j == 0 && j+1 < n){
                    dp[i+1][j+1] = min(dp[i][j] + matrix[i+1][j+1], dp[i+1][j+1]);
                }
                else if(j == n-1){
                    dp[i+1][j-1] = min(dp[i][j] + matrix[i+1][j-1], dp[i+1][j-1]);
                }
                else{
                    dp[i+1][j+1] = min(dp[i][j] + matrix[i+1][j+1], dp[i+1][j+1]);
                    dp[i+1][j-1] = min(dp[i][j] + matrix[i+1][j-1], dp[i+1][j-1]);
                }
            }
        }

        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};