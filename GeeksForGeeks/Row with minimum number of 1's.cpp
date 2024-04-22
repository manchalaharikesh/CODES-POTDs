// DATE: 22-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1
// Question: Row with minimum number of 1's
// Description: Given a 2D binary matrix(1-based indexed) a of dimensions nxm , determine the row that contains the minimum number of 1's.
//              Note: The matrix contains only 1's and 0's. Also, if two or more rows contain the minimum number of 1's, the answer is the lowest of those indices.
// Approach: 1. Code is Self-Explanatory.

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int ans = m+1, r, c = 0;
        
        for(int i = 0; i < n; i++){
            c = 0;
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1){
                    c++;
                }
            }
            
            if(c < ans){
                ans = c;
                r = i;
            }
        }
        
        return r+1;
    }
};