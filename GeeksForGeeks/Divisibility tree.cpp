// DATE: 16-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/divisibility-tree1902/1

// Question: Divisibility tree
// Description: Given a tree with n nodes numbered from 1 to n and n - 1 edges connecting them. The tree is rooted at node 1. Your task is to remove a maximum number of edges from the given tree such that the tree converts into a disjoint union tree and the nodes of connected components left are divisible by 2. If n is odd, then it is allowed to keep exactly one component with an odd number of nodes.
// Approach: 1. In this approach the main idea is to remove an edge if the component being disjoint by the edge removal has even number of nodes.
//              This is done by making a dfs traversal on given tree and to remove an edge (lets say edge between A-B here let A is connected to main land) if component with B has even number of nodes then we can remove edge between A & B.
//              Thus this problem is solved by having a counter for number of nodes below the edge.
//              Code might explain things further.

class Solution {
public:
    int dfs(int curr, vector<bool>& vis, map<int, vector<int>>& m, int& ans){
        int c = 0, t = 0;
        for(int i = 0; i < m[curr].size(); i++){
            if(!vis[m[curr][i]]){
                vis[m[curr][i]] = true;
                t = dfs(m[curr][i], vis, m, ans) + 1;
            }
            
            if(t % 2 == 0 && t != 0){
                t = 0;
                ans++;
            }
            
            c = c + t;
            t = 0;
        }
        
        return c;
    }
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    map<int, vector<int>> m;
	    vector<bool> vis(n+1, false);
	    int ans = 0, c = 0;
	    
	    for(int i = 0; i < n-1; i++){
	        if(m.find(edges[i][0]) == m.end()) m[edges[i][0]] = vector<int>();
	        if(m.find(edges[i][1]) == m.end()) m[edges[i][1]] = vector<int>();
	        
	        m[edges[i][0]].push_back(edges[i][1]);
	        m[edges[i][1]].push_back(edges[i][0]);
	    }
	    
	    vis[1] = true;
	    dfs(1, vis, m, ans);
	    
	    return ans;
	}
};