// DATE: 01-JUL-2024
// Question URL: https://leetcode.com/problems/three-consecutive-odds/description/

// Question: 1550. Three Consecutive Odds
// Description: Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 2; i < arr.size(); i++){
            if(arr[i-2] % 2 && arr[i-1] % 2 && arr[i] % 2) return true;
        }

        return false;
    }
};