// DATE: 31-MAY-2024
// Question URL: https://leetcode.com/problems/single-number-iii/description/

// Question: 260. Single Number III
// Description: Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

//              You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
// Approach: 1. The following approach is a bit manipulation approach.
//              The given vector nums has two numbers which differ in their bits atleast at one position. 
//              The xor of all elements in vector will be the xor of those two unique elements as other elements repeat twice, so those elements xor becomes 0.
//              Then for any set bit in xor it means one of the unique element has this position as set bit while other hasn't.
//              So now we divide the elements into two groups, one has set bit at this particular bit of xor and the other which has no set bit at this particular bit of xor.
//              Each one of our unique elements fall into each group. And also each group get its repeated elements based on particular set bit in xor. 
//              Then we have xor of all the elements in individual groups this must give our unique element each from each group as xor of those repeated elements with in group must become zero.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0, a = 0, b = 0;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            _xor ^= nums[i];
        }

        int set = ffs(_xor)-1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & (1 << set)) a ^= nums[i];
            else b ^= nums[i];
        }

        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};