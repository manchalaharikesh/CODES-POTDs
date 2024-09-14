// DATE: 14-SEP-2024
// Question URL: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/

// Question: 2419. Longest Subarray With Maximum Bitwise AND
// Description: You are given an integer array nums of size n.

//              Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

//              In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
//              Return the length of the longest such subarray.

//              The bitwise AND of an array is the bitwise AND of all the numbers in it.

//              A subarray is a contiguous sequence of elements within an array.
// Approach: 1. Brute Force / Code is Self Explanatory.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int val = INT_MAX, l = 0, l_ans = 0, ans = 0;
        int _max = *max_element(nums.begin(), nums.end());

        for(int i = 0; i <= log2(_max); i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] & (1 << i)){
                    val &= nums[j];
                    l++;

                    if(val == ans){
                        if(l > l_ans) l_ans = l;
                    }
                    else if(val > ans){
                        l_ans = l;
                        ans = val;
                    }
                }
                else{
                    l = 0;
                    val = INT_MAX;
                }
            }

            val = INT_MAX;
            l = 0;
        }

        return l_ans;
    }
};