// DATE: 12-MAY-2024
// Question URL: https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

// Question: 2373. Largest Local Values in a Matrix
// Description: You are given an n x n integer matrix grid.

//              Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

//              maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
//              In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

//              Return the generated matrix.
// Approach: 1. Brute Force / Code is Self-Explanatory.

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size()-2, vector<int>(grid[0].size()-2));
        int _max = 0;

        for(int i = 0; i < grid.size()-2; i++){
            for(int j = 0; j < grid[0].size()-2; j++){
                _max = 0;
                for(int k = i; k < i+3; k++){
                    for(int p = j; p < j+3; p++){
                        _max = max(grid[k][p], _max);
                    }
                }

                ans[i][j] = _max;
            }
        }

        return ans;
    }
};