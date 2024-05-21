// DATE: 21-MAY-2024
// Question URL: https://leetcode.com/problems/subsets/description/

// Question: 78. Subsets
// Description: Given an integer array nums of unique elements, return all possible subsets (the power set).
//              The solution set must not contain duplicate subsets. Return the solution in any order.
// Approach: 1. The solution is a backtracking approach which uses either take or not take the current element into the set.
//              And this approach is started from each element as source to generate all subsets.

class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(v);
            return ;
        }

        v.push_back(nums[idx]);
        backtrack(idx+1, nums, v, ans);
        v.pop_back();
        backtrack(idx+1, nums, v, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> v;

        for(int i = 0; i < nums.size(); i++){
            v.push_back(nums[i]);
            backtrack(i+1, nums, v, ans);
            v.pop_back();
        }
        ans.push_back(v);

        return ans;
    }
};