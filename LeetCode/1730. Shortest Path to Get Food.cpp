// DATE: 17-AUG-2023
// Question URL: https://leetcode.ca/2021-03-13-1730-Shortest-Path-to-Get-Food/

// Question: 1730. Shortest Path to Get Food
// Description: Find the minimum distance of from person(*) to food(#).
// Approach: 1. DP + BFS (BFS always gives the shortest possible distance to reach yi from xi).
//           2. DP stores the distances.

// NOTE: 1. X -> Obstacle or Wall
//       2. O -> Path allowed
//       3. * -> Person (only one such cell is present)
//       4. # -> Food (multiple instances are possible)

#include <bits/stdc++.h>

int main(){
    vector<vector<char>> mat(
        {
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}, 
            {'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
            {'X', 'O', 'O', 'O', 'X', 'O', 'O', '#', 'O', 'X', 'X'},
            {'X', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'X', 'X'},
            {'X', '*', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
            {'X', 'O', 'X', 'O', 'X', 'O', '#', 'O', 'O', 'X', 'X'},
            {'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
            {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        });
    
    int m = mat.size(), n = mat[0].size();
    
    queue<pair<int, int>> q;
    
    vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
    
    pair<int, int> start;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == '#') q.push(pair<int, int>(i, j));
            else if(mat[i][j] == '*') start = pair<int, int>(i, j);
            
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    
    while(!q.empty()){
        pair<int, int> p = q.front();
        int i = p.first, j = p.second;
        int min_cost = INT_MAX;
        
        q.pop();
        
        // left neighborhood
        if(j-1 >= 0 && mat[i][j-1] != 'X'){
            min_cost = min(min_cost, cost[i][j-1]);
            
            if(cost[i][j-1] == INT_MAX)
                q.push(pair<int, int>(i, j-1));
        }
        
        // top neighborhood
        if(i-1 >= 0 && mat[i-1][j] != 'X'){
            min_cost = min(min_cost, cost[i-1][j]);
            
            if(cost[i-1][j] == INT_MAX)
                q.push(pair<int, int>(i-1, j));
        }
        
        // right neighborhood
        if(j+1 < n && mat[i][j+1] != 'X'){
            min_cost = min(min_cost, cost[i][j+1]);
            
            if(cost[i][j+1] == INT_MAX)
                q.push(pair<int, int>(i, j+1));
        }
        
        // bottom neighborhood
        if(i+1 < m && mat[i+1][j] != 'X'){
            min_cost = min(min_cost, cost[i+1][j]);
            
            if(cost[i+1][j] == INT_MAX)
                q.push(pair<int, int>(i+1, j));
        }
        
        cost[i][j] = mat[i][j] == '#' ? 0 : min_cost + 1;
    }
    
    int ans = (cost[start.first][start.second] == INT_MAX) ? -1 : cost[start.first][start.second];
    
    cout << ans;
}