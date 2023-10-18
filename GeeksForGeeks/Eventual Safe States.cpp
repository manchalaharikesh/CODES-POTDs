// DATE: 18-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
// Question: Eventual Safe States
// Description: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

//              A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

//              You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
// Approach: 1. Apply DFS and if at anytime we conclude there is no safe state possible we close that node and mark it unsafe. Repeat it for all other nodes as source nodes which are not determined to be unsafe.

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), isSafe(V, 0), ans;
        
        for(int i = 0; i < V; i++){
            if(isSafe[i] == 0){
                dfs(i, adj, visited, isSafe);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(isSafe[i] == 2) ans.push_back(i);
        }
        
        return ans;
    }
    
    bool dfs(int source, vector<int> adj[], vector<int>& visited, vector<int>& isSafe){
        visited[source] = true;
        for(int i = 0; i < adj[source].size(); i++){
            if(isSafe[adj[source][i]] == 0 && (!visited[adj[source][i]])){
                if(!dfs(adj[source][i], adj, visited, isSafe)){
                    isSafe[source] = 1;
                    break;
                }
            }    
            else if(visited[adj[source][i]]){
                isSafe[source] = 1;
                break;
            }
            else{
                isSafe[source] = isSafe[adj[source][i]];
                if(isSafe[source] == 1) break;
            }
        }
        visited[source] = false;
        if(isSafe[source] == 1) return false;
        
        isSafe[source] = 2;
        return true;
    }
};