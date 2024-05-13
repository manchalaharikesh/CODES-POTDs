// DATE: 13-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1
// Question: Number of Good Components
// Description: Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
//              A component of the graph is good if and only if the component is fully connected.
//              Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in the component, the given graph can be a disconnected graph. 
// Approach: 1. The idea is for a component or sub-graph to be completely connected each node must have a degree equal to n-1 where n is the number of nodes in that component.
//              Thus in this solution we traverse through each unique component, to find the nodes in that component and verify if this component is a good component by checking for degree of the nodes to be equal to n-1 where n is the numebr of nodes in this component.

class Solution {
  public:
    void dfs(int src, vector<int> g[], vector<int>& ele, vector<bool>& vis){
        for(int i = 0; i < g[src].size(); i++){
            if(!vis[g[src][i]]){
                vis[g[src][i]] = true;
                ele.push_back(g[src][i]);
                dfs(g[src][i], g, ele, vis);
            }
        }
    }
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int> g[v+1];
        vector<bool> vis(v+1, false);
        int ans = 0;
        bool flag = true;
        
        for(int i = 0; i < e; i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 1; i <= v; i++){
            if(!vis[i]){
                vector<int> ele;
                
                vis[i] = true;
                ele.push_back(i);
                
                dfs(i, g, ele, vis);
                
                flag = true;
                
                for(int j = 0; j < ele.size(); j++){
                    if(g[ele[j]].size() != ele.size()-1){
                        flag = false;
                        break;
                    }
                }
                
                if(flag) ans++;
            }
        }
        
        return ans;
    }
};
