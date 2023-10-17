// DATE: 17-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1
// Question: Transitive Closure of a Graph
// Description: Given a directed graph, determine whether a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here, vertex j is reachable from another vertex i means that there is a path from vertex i to j. The reachability matrix is called the transitive closure of a graph. The directed graph is represented by an adjacency matrix where there are N vertices.
// Approach: 1. Implement DFS for every node and find all reachables.

class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<vector<int>> visited(N, vector<int>(N, 0));
        
        for(int i = 0; i < N; i++){
            graph[i][i] = 1;
        }
        
        for(int i = 0; i < N; i++){
            dfs(graph, visited, i, i);
        }
        
        return visited;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int source, int curr){
        for(int j = 0; j < graph.size(); j++){
            if(source == j && curr == source){
                visited[source][j] = 1;
            }
            else if(graph[curr][j] == 1 && visited[source][j] == 0){
                visited[source][j] = 1;
                dfs(graph, visited, source, j);
            }
        }
    }
};