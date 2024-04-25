// DATE: 25-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1
// Question: Maximum sum of hour glass
// Description: Given two integers n, m and a 2D matrix mat of dimensions nxm, the task is to find the maximum sum of an hourglass.
//              An hourglass is defined as a part of the matrix with the following form:

//              A B C
//                D
//              E F G

//              Return -1 if any hourglass is not found.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        if(n < 3) return -1;
        int ans = INT_MIN, sum = 0, row1 = 0, row2 = 0;
        
        for(int i = 0; i < n-2; i++){
            row1 = 0;
            row2 = 0;
            for(int j = 0; j < m; j++){
                if(j < 2){
                    row1 += mat[i][j];
                    row2 += mat[i+2][j];
                }
                else{
                    row1 += mat[i][j];
                    row2 += mat[i+2][j];
                    sum = row1 + row2 + mat[i+1][j-1];
                    if(ans < sum) ans = sum;
                    row1 -= mat[i][j-2];
                    row2 -= mat[i+2][j-2];
                }
            }
        }
        
        return ans;
    }
};