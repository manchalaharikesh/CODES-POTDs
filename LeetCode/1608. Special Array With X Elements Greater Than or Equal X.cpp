// DATE: 27-MAY-2024
// Question URL: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

// Question: 1608. Special Array With X Elements Greater Than or Equal X
// Description: You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

//              Notice that x does not have to be an element in nums.

//              Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
// Approach: 1. Check for every possible x as x range lies from [1, n] where n is array size.

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;

        for(int c = 1; c <= nums.size(); c++){
            i = 0;
            for(; i < nums.size(); i++){
                if(nums[i] >= c) break;
            }
            if(c == nums.size()-i) return c;
        }

        return -1;
    }
};