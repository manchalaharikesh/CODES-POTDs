// DATE: 19-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1
// Question: Level of Nodes
// Description: Given an integer X and an undirected acyclic graph with V nodes, labeled from 0 to V-1, and E edges, find the level of node labeled as X.

//              Level is the minimum number of edges you must travel from the node 0 to some target.

//              If there doesn't exists such a node that is labeled as X, return -1.
// Approach: 1. Implement Level Order Traversal for all unvisited nodes and store node along with its level in the queue this makes up the solution.

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int, int>> q;
	    vector<int> visited(V, 0);
	    
	    q.push({0, 0});
	    visited[0] = 1;
	    
	    while(!q.empty()){
	        int n = q.front().first, l = q.front().second;
	        q.pop();
	        
	        if(n == X) return l;
	        for(int i = 0; i < adj[n].size(); i++){
	            if(adj[n][i] == X) return l+1;
	            if(visited[adj[n][i]] == 0){
	                 q.push({adj[n][i], l+1});
	                 visited[adj[n][i]] = 1;
	            }
	        }
	    }
	    
	    return -1;
	}
};