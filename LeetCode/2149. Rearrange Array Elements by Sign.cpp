// DATE: 14-FEB-2024
// Question URL: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// Question: 2149. Rearrange Array Elements by Sign
// Description: You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

//              You should rearrange the elements of nums such that the modified array follows the given conditions:

//              Every consecutive pair of integers have opposite signs.
//              For all integers with the same sign, the order in which they were present in nums is preserved.
//              The rearranged array begins with a positive integer.
//              Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int p1 = 0, p2 = 1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans[p1] = nums[i];
                p1+=2;
            }
            else{
                ans[p2] = nums[i];
                p2+=2;
            }
        }

        return ans;
    }
};