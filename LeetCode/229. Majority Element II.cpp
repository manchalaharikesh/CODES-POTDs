// DATE: 05-OCT-2023
// Question URL: https://leetcode.com/problems/majority-element-ii/

// Question: 229. Majority Element II
// Description: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

// Approach: 1. Use hashmap to store count.
//           2. Use sorting then use two pointers to get count.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p1 = 0, p2 = 0;
        int n = nums.size();
        vector<int> ans;

        while(p2 < n){
            while(p2 < n && nums[p1] == nums[p2]) p2++;
            if((p2-p1) > n/3) ans.push_back(nums[p1]);
            p1 = p2;
        }

        return ans;
    }
};