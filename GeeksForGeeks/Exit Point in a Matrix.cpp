// DATE: 26-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1
// Question: Exit Point in a Matrix
// Description: Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        bool right = true, left = false, up = false, down = false;
        int i = 0, j = 0;
        vector<int> ans;
        
        while(true){
            while(right && j < m){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 0;
                    right = false;
                    down = true;
                    i++;
                }
                else{
                    j++;
                }
            }
            
            while(down && i < n){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 0;
                    down = false;
                    left = true;
                    j--;
                }
                else{
                    i++;
                }
            }
            
            while(left && j >= 0){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 0;
                    left = false;
                    up = true;
                    i--;
                }
                else{
                    j--;
                }
            }
            
            while(up && i >= 0){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 0;
                    up = false;
                    right = true;
                    j++;
                }
                else{
                    i--;
                }
            }
            
            if(i < 0 || j < 0){
                ans.push_back(i < 0 ? 0 : i);
                ans.push_back(j < 0 ? 0 : j);
                break;
            }
            if(i == n || j == m){
               ans.push_back(i == n ? n-1 : i);
               ans.push_back(j == m ? m-1 : j);
               break;
            }
        }
        
        return ans;
    }
};