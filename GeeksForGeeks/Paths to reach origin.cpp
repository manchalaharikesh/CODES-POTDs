// DATE: 24-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

// Question: Paths to reach origin
// Description: You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.
// Approach: 1. The dp[i][0] and dp[0][j] will all have 1 as there is only one path possible for (x, 0) and (0, y) to reach (0, 0). Then for every dp[i][j] we have dp[i][j] = dp[i-1][j] + dp[i][j-1].

class Solution
{
public:
    int ways(int x, int y)
    {
        vector<vector<int>> m(x+1, vector<int>(y+1, 0));
        
        for(int i = 1; i <= x; i++){
            m[i][0] = 1;
        }
        for(int j = 1; j <= y; j++){
            m[0][j] = 1;
        }
        
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= y; j++){
                m[i][j] = (m[i-1][j] + m[i][j-1]) % 1000000007;
            }
        }
        
        return m[x][y];
    }
};