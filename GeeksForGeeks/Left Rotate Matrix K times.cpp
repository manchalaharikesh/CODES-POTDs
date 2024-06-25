// DATE: 25-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1
// Question: Left Rotate Matrix K times
// Description: You are given an integer k and matrix mat. Rotate the elements of the given matrix to the left k times and return the resulting matrix.
// Approach: 1. Code is Self-Explanatory. Dry Run the code for better understanding.

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        if(k % mat[0].size() == 0) return mat;
        
        // for every m*k we get original matrix thus we ignore them by making k = k % m
        k = k % mat[0].size();
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        int p;
        
        for(int j = 0; j < mat[0].size(); j++){
            // to get the resultant column after applying k left rotations
            p = j >= k ? j - k : mat[0].size() - k + j;
            for(int i = 0; i < mat.size(); i++){
                ans[i][p] = mat[i][j];
            }
        }
        
        return ans;
    }
};