// DATE: 10-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1
// Question: Combination Sum II
// Description: Given an array of integers arr, the length of the array n, and an integer k, find all the unique combinations in arr where the sum of the combination is equal to k. Each number can only be used once in a combination.
// Approach: 1. Sort the initial arr to terminate search at early stages of k < 0. Generate all the combinations that sum upto k. Then sort each combination and store it in a set. At the end push vectors in set to vector of vectors which is the answer to be returned.

class Solution{
public:
    void solve(int i, vector<int>& arr, int k, set<vector<int>>& s, vector<int>& v){
        if(k < 0) return ;
        if(k == 0){
            sort(v.begin(), v.end());
            s.insert(v);
            return ;
        }
        if(i == arr.size()) return ;
        
        v.push_back(arr[i]);
        solve(i+1, arr, k-arr[i], s, v);
        v.pop_back();
        solve(i+1, arr, k, s, v);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        vector<vector<int>> ans;
        vector<int> v;
        set<vector<int>> s;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++){
            v.push_back(arr[i]);
            solve(i+1, arr, k-arr[i], s, v);
            v.pop_back();
        }
        
        for (const auto& vec : s) {
            ans.push_back(vec);
        }
        
        return ans;
    }
};