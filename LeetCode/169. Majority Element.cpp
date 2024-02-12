// DATE: 12-FEB-2024
// Question URL: https://leetcode.com/problems/majority-element/description/

// Question: 169. Majority Element
// Description: Given an array nums of size n, return the majority element.

//              The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int ans;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }

        for(auto it: m){
            if(it.second > nums.size() / 2){
                 ans = it.first;
                break;
            }
        }

        return ans;
    }
};