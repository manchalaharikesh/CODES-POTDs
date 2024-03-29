// DATE: 29-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
// Question: Euler Circuit in an Undirected Graph
// Description: Eulerian Path is a path in a graph that visits every edge exactly once. Eulerian Circuit is an Eulerian Path that starts and ends on the same vertex. Given the number of vertices v and adjacency list adj denoting the graph. Find that there exists the Euler circuit or not. Return 1 if there exist  alteast one eulerian path else 0.
// Approach: 1. Code is Self-Explanatory.

class Solution {
public:
    bool dfs(int src, int curr, vector<int> adj[], vector<vector<bool>>& visited, int edges){
        if(src == curr && edges == 0) return true;
        else if(edges == 0) return false;
        
        for(int i = 0; i < adj[curr].size(); i++){
            if(!visited[curr][adj[curr][i]]){
                visited[curr][adj[curr][i]] = true;
                visited[adj[curr][i]][curr] = true;
                
                if(dfs(src, adj[curr][i], adj, visited, edges-2)) return true;
                else return false;
            }
        }
    }
    
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    vector<vector<bool>> visited(v, vector<bool>(v, false));
	    map<int, vector<int>> hm;
	    int edges = 0;
	    
	    for(int i = 0; i < v; i++){
	        edges = edges + adj[i].size();
	    }
	    
	    return dfs(0, 0, adj, visited, edges);
	}

};