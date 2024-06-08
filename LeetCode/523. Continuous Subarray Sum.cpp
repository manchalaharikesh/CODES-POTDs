// DATE: 08-JUN-2024
// Question URL: https://leetcode.com/problems/continuous-subarray-sum/description/

// Question: 523. Continuous Subarray Sum
// Description: Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

//              A good subarray is a subarray where:

//              its length is at least two, and
//              the sum of the elements of the subarray is a multiple of k.
//              Note that:

//              A subarray is a contiguous part of the array.
//              An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
// Approach: 1. I can't explain this here, better find a solution on LeetCode - Solutions.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(), 0);
        map<int, int> m;
        int _min = INT_MAX, _max, del = 0, n = nums.size(); 
        pre[0] = nums[0];

        m[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            pre[i] = pre[i-1] + nums[i];
            m[pre[i]]++;
        }

        for(int i = 1; i < nums.size(); i++){
            if((pre[i] - del) % k == 0) _min = pre[i] - del;
            else _min = ((pre[i]-del)/k)*k + k;

            if((pre[n-1]-del) % k == 0) _max = pre[n-1] - del;
            else _max = ((pre[n-1]-del)/k)*k;

            for(int j = _min; j <= _max; j+=k){
                if(m.find(del + j) != m.end()) return true;
            }

            del = pre[i-1];
        }
        
        return false;
    }
};