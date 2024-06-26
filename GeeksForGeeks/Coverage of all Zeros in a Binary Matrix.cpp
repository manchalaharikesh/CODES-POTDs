// DATE: 26-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1
// Question: Coverage of all Zeros in a Binary Matrix
// Description: Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.
// Approach: 1. At each 0 element of matrix look into its 4-connected elements (as if they exists). Then increment a counter / ans variable as we get 1 in its neighborhood.

class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int ans = 0;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(i-1 >= 0 && matrix[i-1][j] == 1) ans++;
                    if(j-1 >= 0 && matrix[i][j-1] == 1) ans++;
                    if(i+1 < matrix.size() && matrix[i+1][j] == 1) ans++;
                    if(j+1 < matrix[0].size() && matrix[i][j+1] == 1) ans++;
                }
            }
        }
        
        return ans;
    }
};