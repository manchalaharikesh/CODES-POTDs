// DATE: 27-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
// Question: Find shortest safe route in a matrix
// Description: Given a matrix mat[][] with r rows and c columns, where some cells are landmines (marked as 0) and others are safe to traverse. Your task is to find the shortest safe route from any cell in the leftmost column to any cell in the rightmost column of the mat. You cannot move diagonally, and you must avoid both the landmines and their adjacent cells (up, down, left, right), as they are also unsafe.
// Approach: 1. Use BFS for every node in col-0 as source node. And continue bfs an node {i, j} only if cost[i][j] > cost[source] + 1.

class Solution
{
public:
    void markMines(vector<vector<int>>& mat){
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    if(i-1 >= 0 && mat[i-1][j] == 1) mat[i-1][j] = -1;
                    if(i+1 < mat.size() && mat[i+1][j] == 1) mat[i+1][j] = -1;
                    if(j-1 >= 0 && mat[i][j-1] == 1) mat[i][j-1] = -1;
                    if(j+1 < mat[0].size() && mat[i][j+1] == 1) mat[i][j+1] = -1;
                }
            }
        }    
    }
    
    void bfs(vector<vector<int>>& mat, vector<vector<bool>>& visited, queue<pair<int, int>>& q, vector<vector<int>>& cost){
        if(q.front().second == mat[0].size()-1){
            visited[q.front().first][q.front().second] = false;
            q.pop();
            if(!q.empty()) bfs(mat, visited, q, cost);
            return;
        }
        
        pair<int, int> curr = q.front();
        int i = curr.first, j = curr.second;
        q.pop();
        
        if(j+1 < mat[0].size() && mat[i][j+1] == 1 && !visited[i][j+1] && cost[i][j+1] > cost[i][j] + 1){
            visited[i][j+1] = true;
            q.push({i, j+1});
            cost[i][j+1] = cost[i][j] + 1;
        }
        if(i-1 >= 0 && mat[i-1][j] == 1 && !visited[i-1][j] && cost[i-1][j] > cost[i][j] + 1){
            visited[i-1][j] = true;
            q.push({i-1, j});
            cost[i-1][j] = cost[i][j] + 1;
        }
        if(i+1 < mat.size() && mat[i+1][j] == 1 && !visited[i+1][j] && cost[i+1][j] > cost[i][j] + 1){
            visited[i+1][j] = true;
            q.push({i+1, j});
            cost[i+1][j] = cost[i][j] + 1;
        }
        if(j-1 >= 0 && mat[i][j-1] == 1 && !visited[i][j-1] && cost[i][j-1] > cost[i][j] + 1){
            visited[i][j-1] = true;
            q.push({i, j-1});
            cost[i][j-1] = cost[i][j] + 1;
        }
        
        if(!q.empty()) bfs(mat, visited, q, cost);
        visited[i][j] = false;
    }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        vector<vector<int>> cost(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        int ans = INT_MAX;
        
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][0] == 1) cost[i][0] = 1;
        }
        
        markMines(mat);
        
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][0] == 1 && !visited[i][0]){
                visited[i][0] = true;
                q.push({i, 0});
                bfs(mat, visited, q, cost);
                visited[i][0] = false;
            }
        }
        
        for(int i = 0; i < mat.size(); i++){
            ans = min(ans, cost[i][mat[0].size()-1]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};