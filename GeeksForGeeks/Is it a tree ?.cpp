// DATE: 24-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/is-it-a-tree/1
// Question: Is it a tree ?
// Description: You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.

//              Note: The input graph can have self-loops and multiple edges.
// Approach: 1. Brute Force / Code Self Explanatory.

class Solution {
  public:
    bool dfs(int src, int curr, map<int, vector<int>>& hm, vector<int>& visited, int reg, vector<int>& region){
        for(int node: hm[curr]){
            if(visited[node] == 1 && src != node) return false;
            else if(visited[node] == 0){
                visited[node] = 1;
                // for detecting disconnected components
                region[node] = reg;
                if(!dfs(curr, node, hm, visited, reg, region)) return false;
            }
        }   
        
        return true;
    }
    
    int isTree(int n, int m, vector<vector<int>> &adj) {
        map<int, vector<int>> hm;
        vector<int> visited(n, 0), region(n, 0);
        set<pair<int, int>> s;
        int reg = 0;
        
        if(n == 1 && m == 0) return 1;
        else if(n > 1 && m == 0) return 0;
        
        for(int i = 0; i < m; i++){
            // self-loop
            if(adj[i][0] == adj[i][1]) return 0;
            
            if(s.find({adj[i][0], adj[i][1]}) == s.end()){
                s.insert({adj[i][0], adj[i][1]});
                s.insert({adj[i][1], adj[i][0]});
                
                if(hm.find(adj[i][0]) == hm.end()) hm[adj[i][0]] = vector<int>();
                hm[adj[i][0]].push_back(adj[i][1]);
                
                if(hm.find(adj[i][1]) == hm.end()) hm[adj[i][1]] = vector<int>();
                hm[adj[i][1]].push_back(adj[i][0]);
            }
        }
        
        for(int i = 0; i < n; i++){
            // has no edge
            if(hm.find(i) == hm.end()) return 0;
            if(visited[i] == 0){
                visited[i] = 1;
                if(!dfs(i, i, hm, visited, reg, region)){
                    return 0;
                }
                reg++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(region[i] != 0) return 0;
        }
        
        return 1;
    }
};