// DATE: 29-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problem-of-the-day
// Question: Number of Enclaves
// Description: For a given grid of size N X M with 0s and 1s. Where 1 represent land and 0 represent water. Find the cound of all landfalls from which cannot walk off the boundary of the grid in any number of moves.
// Approach: 1. From grid boundary apply DFS with 4-adjacency at every possible landfall. 
//              Then for each of the landfall in this DFS traversal make that position invalid as from this we can reach out to the grid boundary. 
//              Then after removing all possible paths to reach out to grid boundaries we count all landfalls which are still valid.

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> valid(n, vector<bool>(m, true));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(grid[i][j] == 1 && valid[i][j]){
                        solve(grid, valid, i, j);
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && valid[i][j]) ans++;
            }
        }
        
        return ans;
    }
    
    void solve(vector<vector<int>>& grid, vector<vector<bool>>& valid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        stack<pair<int, int>> st;
        
        st.push({i, j});
        valid[i][j] = false;
        
        while(!st.empty()){
            int x = st.top().first, y = st.top().second;
            st.pop();
            // top
            if(x-1 >= 0 && grid[x-1][y] == 1 && valid[x-1][y]){
                st.push({x-1, y});
                valid[x-1][y] = false;
            }
            // left
            if(y-1 >= 0 && grid[x][y-1] == 1 && valid[x][y-1]){
                st.push({x, y-1});
                valid[x][y-1] = false;
            }
            // right
            if(y+1 < m && grid[x][y+1] == 1 && valid[x][y+1]){
                st.push({x, y+1});
                valid[x][y+1] = false;
            }
            // bottom
            if(x+1 < n && grid[x+1][y] == 1 && valid[x+1][y]){
                st.push({x+1, y});
                valid[x+1][y] = false;
            }
        }
    }
};