// DATE: 01-FEB-2024
// Question URL: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

// Question: 2966. Divide Array Into Arrays With Max Difference
// Description: You are given an integer array nums of size n and a positive integer k.

//              Divide the array into one or more arrays of size 3 satisfying the following conditions:

//              Each element of nums should be in exactly one array.
//              The difference between any two elements in one array is less than or equal to k.
//              Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.
// Approach: 1. Code is Self-Explanatory.

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int p1 = 0, p2 = p1 + 2;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        while(p2 < nums.size()){
            if(nums[p2] - nums[p1] > k) return vector<vector<int>>();
            p1 = p2 + 1;
            p2 = p1 + 2;
        }

        for(int i = 0; i < nums.size() - 2; i += 3){
            vector<int> v;
            for(int j = i; j < i + 3; j++){
                v.push_back(nums[j]);
            }

            ans.push_back(v);
        }

        return ans;
    }
};