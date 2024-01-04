// DATE: 04-JAN-2024
// Question URL: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

// Question: 2870. Minimum Number of Operations to Make Array Empty
// Description: You are given a 0-indexed array nums consisting of positive integers.

//              There are two types of operations that you can apply on the array any number of times:

//              Choose two elements with equal values and delete them from the array.
//              Choose three elements with equal values and delete them from the array.
//              Return the minimum number of operations required to make the array empty, or -1 if it is not possible.
// Approach: 1. Store the freq of each element and then find number of three-two based operations to be done based on freq.

class Solution {
public:
    int threes_twos(int n){
        int three = n/3, two = 0;
        int rem = n - 3*(three);

        if(rem % 2 != 0){
            three--;
            rem += 3;
        }

        two = rem/2;

        return three + two;
    }

    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size(), ans = 0, out;
        
        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 1;
            else m[nums[i]]++;
        }

        for(auto i: m){
            if(i.second == 1) return -1;
            ans += threes_twos(i.second);
        }

        return ans;
    }
};