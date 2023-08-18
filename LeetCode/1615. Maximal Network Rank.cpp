// DATE: 18-AUG-2023
// Question URL: https://leetcode.com/problems/maximal-network-rank/

// Question: 1615. Maximal Network Rank
// Description: Find the highest network rank in the given bidirectional graph of city connections.
// Approach: 1. Create the adjList, adjMat for given nodes.
//           2. For all possible pairs, check for individual nodes degrees.
//           3. If the pair is really connected in the graph make sum = deg(node1) + deg(node2) - 1.
//           4. Else make sum = deg(node1) + deg(node2).
//           5. Return the max possible value of sum.

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);

            mat[roads[i][0]][roads[i][1]] = 1;
            mat[roads[i][1]][roads[i][0]] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int sum = adj[i].size() + adj[j].size();
                if(mat[i][j] == 1){
                    sum--;
                }

                if(sum > ans) ans = sum;
            }
        }

        return ans;
    }
};