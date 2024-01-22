// DATE: 22-JAN-2024
// Question URL: https://leetcode.com/problems/set-mismatch/description/

// Question: 645. Set Mismatch
// Description: You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

//              You are given an integer array nums representing the data status of this set after the error.

//              Find the number that occurs twice and the number that is missing and return them in the form of an array.
// Approach: 1. Mark the occurence of the num[i] in it's index num[nums[i]] and handle overflows. And if num[i] > n i is duplicate. Find missing from sum of natural numbers.

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), mod = n + 1, rep, mis, idx, val, sum = 0;

        for(int i = 0; i < n; i++){
            idx = nums[i] % mod;
            val = idx;
            idx = idx == n ? 0 : idx;
            sum += val;
            if(nums[idx] > n){
                rep = val;
                sum -= val;
            }
            else{
                nums[idx] = mod + nums[idx];
            }
        }

        mis = n * (n + 1) / 2 - sum;
        
        return vector<int>{rep, mis};
    }
};