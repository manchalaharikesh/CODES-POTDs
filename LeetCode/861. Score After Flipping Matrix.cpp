// DATE: 13-MAY-2024
// Question URL: https://leetcode.com/problems/score-after-flipping-matrix/description/

// Question: 861. Score After Flipping Matrix
// Description: You are given an m x n binary matrix grid.

//              A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

//              Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

//              Return the highest possible score after making any number of moves (including zero moves).
// Approach: 1. Here we have few aspects to remember:
//              1.1 If MSB bit is not set then making it set makes the number definitely larger than the original number (1000) is definitely larger than (0111).
//              1.2 If among three numbers 1011, 1001, 1101 as the number of zeros are more than ones in 2nd LSB flipping the bits along this col will give the final sum definitely larger than original sum i.e., (1001 + 1011 + 1111) > (1011 + 1001 + 1101).
//              Thus by above two remarks we can solve this problem, hereafter the Code is Self-Explanatory.

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int zero = 0, one = 0, n = 0, m, ans = 0;

        // modify MSB to 1
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < grid[0].size(); j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        // flip each cols only if zeros are more than ones
        for(int j = 1; j < grid[0].size(); j++){
            zero = 0;
            one = 0;
            for(int i = 0; i < grid.size(); i++){
                if(grid[i][j] == 1) one++;
                else zero++;
            }

            if(zero > one){
                for(int i = 0; i < grid.size(); i++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        m = grid[0].size()-1;
        for(int i = 0; i < grid.size(); i++){
            n = 0;
            for(int j = grid[0].size()-1; j >= 0; j--){
                n = n | grid[i][j]*(1 << (m - j));
            }

            ans = ans + n;
        }

        return ans;
    }
};