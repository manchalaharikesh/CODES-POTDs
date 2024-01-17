// DATE: 17-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
// Question: All Unique Permutations of an array
// Description: Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.
// Approach: 1. Sort the given array and to eliminate duplicate sequences we construct an index array which represents the index to be moved to, skip the repeating elements which cause the repeated sequences.

class Solution {
  public:
    void solve(int n, vector<int>& arr, vector<int> index, vector<bool>& visited, vector<vector<int>>& res, vector<int> seq){
        if(seq.size() == n){
            res.push_back(seq);
            return ;
        }
        
        int idx = 0;
        while(idx < n){
            if(!visited[idx]){
                seq.push_back(arr[idx]);
                visited[idx] = true;
                solve(n, arr, index, visited, res, seq);
                
                seq.pop_back();
                visited[idx] = false;
                
                if(idx + 1 < n && arr[idx] == arr[idx + 1]){
                    idx = index[idx + 1] - 1;
                }
            }
            idx++;
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<int> index(n, n), seq;
        vector<bool> visited(n, false);
        vector<vector<int>> res;
        
        sort(arr.begin(), arr.end());
        
        int p1 = 0, p2 = 1;
        while(p2 < n){
            while(p2 < n && arr[p1] == arr[p2]){
                p2++;
            }
            index[p1] = p2;
            p1++;
        }
        
        solve(n, arr, index, visited, res, seq);
        
        return res;
    }
};