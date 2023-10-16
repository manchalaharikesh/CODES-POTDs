// DATE: 16-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/making-a-large-island/1

// Question: Making a Larger Island
// Description: You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1. A group of connected 1s forms an island. Two 1s are connected if they share one of their sides with each other.

//              Return the size of the largest island in the grid after applying this operation.
// Approach: 1. Make BFS/DFS for each possible island and have a unique marker for each and store each island size in map as <marker, size>. Now for each 0 try the possible unqiue island connections and find the new island size.

class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        map<int, int> hm;
        int marker = 0, size = 0, ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    size = traverseIsland(grid, visited, i, j, ++marker);
                    hm[marker] = size;
                    ans = ans < size ? size : ans;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    set<int> s;
                    int temp = 0;
                    
                    // top
                    if(i-1 >= 0 && visited[i-1][j] != 0) s.insert(visited[i-1][j]);
                    // left
                    if(j-1 >= 0 && visited[i][j-1] != 0) s.insert(visited[i][j-1]);
                    // bottom
                    if(i+1 < grid.size() && visited[i+1][j] != 0) s.insert(visited[i+1][j]);
                    // right
                    if(j+1 < grid[0].size() && visited[i][j+1] != 0) s.insert(visited[i][j+1]);
                    
                    for(auto i: s) temp = temp + hm[i];
                    
                    ans = ans < temp + 1 ? temp + 1 : ans;
                }
            }
        }
        
        return ans;
    }
    
    int traverseIsland(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int marker){
        int size = 0;
        queue<pair<int, int>> q;
        
        q.push({i, j});
        visited[i][j] = marker;
        
        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            size++;
            
            // top
            if(i-1 >= 0 && grid[i-1][j] == 1 && visited[i-1][j] == 0){ 
                visited[i-1][j] = marker;
                q.push({i-1, j});
            }
            // left
            if(j-1 >= 0 && grid[i][j-1] == 1 && visited[i][j-1] == 0){ 
                visited[i][j-1] = marker;
                q.push({i, j-1});
            }
            // bottom
            if(i+1 < grid.size() && grid[i+1][j] == 1 && visited[i+1][j] == 0){ 
                visited[i+1][j] = marker;
                q.push({i+1, j});
            }
            // right
            if(j+1 < grid[0].size() && grid[i][j+1] == 1 && visited[i][j+1] == 0){ 
                visited[i][j+1] = marker;
                q.push({i, j+1});
            }
        }
        
        return size;
    }
};