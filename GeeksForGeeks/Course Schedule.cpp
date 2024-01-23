// DATE: 23-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/course-schedule/1
// Question: Course Schedule
// Description: There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
//              Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
//              Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Driver code will print "No Ordering Possible", on returning an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.
// Approach: 1. BRUTE FORCE (DFS) Code is Self-Explanatory.

class Solution
{
  public:
    bool dfs(int node, map<int, vector<int>>& hm, vector<int>& visited, vector<int>& res){
        // 0 -> currently not visited
        // 1 -> already visited in current iteration
        // 2 -> already appended to result in earlier iteration
        
        if(hm.find(node) == hm.end()) return true;
        
        for(int i: hm[node]){
            if(visited[i] == 0){
                visited[i] = 1;
                if(!dfs(i, hm, visited, res)) return false;
                visited[i] = 2;
                res.push_back(i);
            }
            else if(visited[i] == 1) return false;
        }
        return true;
    }
  
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> visited(n, 0), cardinality(n, 0), res;
        map<int, vector<int>> hm;
        
        for(int i = 0; i < m; i++){
            if(hm.find(prerequisites[i][0]) == hm.end()){
                hm[prerequisites[i][0]] = vector<int>();
            }
            hm[prerequisites[i][0]].push_back(prerequisites[i][1]);
            cardinality[prerequisites[i][1]]++;
        }
        
        for(int i = 0; i < n; i++){
            if(cardinality[i] == 0){
                visited[i] = 1;
                if(!dfs(i, hm, visited, res)){
                    return vector<int>();
                }
                visited[i] = 2;
                res.push_back(i);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(visited[i] != 2) return vector<int>();
        }
        
        return res;
    }
};