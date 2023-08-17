// DATE: 17-AUG-2023
// Question URL: https://leetcode.com/problems/01-matrix/

// Question: 542. 01 Matrix 
// Description: Find the minimum distance of cell with 1 from cell with 0.
// Approach: 1. DP + BFS (BFS always gives the shortest possible distance to reach y from xi).
//           2. DP stores the distances.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> cost(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push(pair<int, int>(i, j));
                } 
            }
        }

        while(!q.empty()){
            pair<int, int> p = q.front();
            int i = p.first, j = p.second;
            
            q.pop();

            // left neighborhood
            if(j-1 >= 0 && mat[i][j-1] == 1 && cost[i][j-1] == 0){
                cost[i][j-1] = cost[i][j] + 1;
                q.push(pair<int, int>(i, j-1));
            }
            // top neighborhood
            if(i-1 >= 0 && mat[i-1][j] == 1 && cost[i-1][j] == 0){
                cost[i-1][j] = cost[i][j] + 1;
                q.push(pair<int, int>(i-1, j));
            }
            // right neighborhood
            if(j+1 < n && mat[i][j+1] == 1 && cost[i][j+1] == 0){
                cost[i][j+1] = cost[i][j] + 1;
                q.push(pair<int, int>(i, j+1));
            }
            // bottom neighborhood
            if(i+1 < m && mat[i+1][j] == 1 && cost[i+1][j] == 0){
                cost[i+1][j] = cost[i][j] + 1;
                q.push(pair<int, int>(i+1, j));
            }
        }

        return cost;
    }
};