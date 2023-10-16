// DATE: 16-OCT-2023
// Question URL: https://leetcode.com/problems/pascals-triangle-ii/

// Question: 119. Pascal's Triangle II
// Description: Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// Approach: 1. Apply DP by generating ith row from (i-1)th row.

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int mod = 1000000007;

        if(n == 1){
            arr[0][0] = 1;
            return arr[0];
        }
        else if(n==2){
            arr[1][0] = 1;
            arr[1][1] = 1;
            return arr[1];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0 || i == j) arr[i][j] = 1;
                else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]);
            }
        }

        return arr[n-1];
    }
};