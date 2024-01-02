// DATE: 02-JAN-2024
// Question URL: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

// Question: 2610. Convert an Array Into a 2D Array With Conditions
// Description: You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

//              The 2D array should contain only the elements of the array nums.
//              Each row in the 2D array contains distinct integers.
//              The number of rows in the 2D array should be minimal.
//              Return the resulting array. If there are multiple answers, return any of them.

//              Note that the 2D array can have a different number of elements on each row.
// Approach: 1. Store freq of elements and create matrix of rows with max freq and then store them in each row.

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> m;
        int _max = 0;

        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]]++;
            else m[nums[i]]++;

            if(m[nums[i]] > _max) _max = m[nums[i]];
        }

        vector<vector<int>> ans(_max);

        for(auto i: m){
            for(int j = 0; j < i.second; j++){
                ans[j].push_back(i.first);
            }
        }

        return ans;
    }
};