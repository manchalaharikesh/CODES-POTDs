// DATE: 14-MAY-2024
// Question URL: https://leetcode.com/problems/path-with-maximum-gold/description/

// Question: 1219. Path with Maximum Gold
// Description: In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

//              Return the maximum amount of gold you can collect under the conditions:

//              Every time you are located in a cell you will collect all the gold in that cell.
//              From your position, you can walk one step to the left, right, up, or down.
//              You can't visit the same cell more than once.
//              Never visit a cell with 0 gold.
//              You can start and stop collecting gold from any position in the grid that has some gold.
// Approach: 1. Apply dfs in all directions by choosing every node as source node.
//              And during each dfs move in four directions (left, right, top and bottom), only towards position without zero (as mentioned in constraints).
//              And also in a dfs when we pass over the current position mark it as zero as we are collecting the coins at that position.
//              While traversing back restore the coins in that position for another dfs traversal with different source.

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int& c, int& ans){
        int t;
        //left
        if(j-1 >= 0 && grid[i][j-1] != 0){
            t = grid[i][j-1];
            grid[i][j-1] = 0;
            c = c + t;
            dfs(i, j-1, grid, c, ans);
            c = c - t;
            grid[i][j-1] = t;
        }

        //top
        if(i-1 >= 0 && grid[i-1][j] != 0){
            t = grid[i-1][j];
            grid[i-1][j] = 0;
            c = c + t;
            dfs(i-1, j, grid, c, ans);
            c = c - t;
            grid[i-1][j] = t;
        }

        //bottom
        if(i+1 < grid.size() && grid[i+1][j] != 0){
            t = grid[i+1][j];
            grid[i+1][j] = 0;
            c = c + t;
            dfs(i+1, j, grid, c, ans);
            c = c - t;
            grid[i+1][j] = t;
        }
        
        //right
        if(j+1 < grid[0].size() && grid[i][j+1] != 0){
            t = grid[i][j+1];
            grid[i][j+1] = 0;
            c = c + t;
            dfs(i, j+1, grid, c, ans);
            c = c - t;
            grid[i][j+1] = t;
        }

        ans = max(ans, c);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int c = 0, ans = 0, t;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0){
                    t = grid[i][j];
                    grid[i][j] = 0;
                    c = t;

                    dfs(i, j, grid, c, ans);

                    grid[i][j] = t;
                    c = 0;
                }
            }
        }

        return ans;
    }
};