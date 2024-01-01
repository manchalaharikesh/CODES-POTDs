// DATE: 01-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
// Question: Array Pair Sum Divisibility Problem
// Description: Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
// Approach: 1. Groups elements by remainder when divided by k, then check if we have equal number of other group elements with remainder (k - curr_remainder) which makes the pair of them divisible by k.

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        map<int, int> m;
        bool ans = false;
        int rem;
        
        if(nums.size() % 2 != 0) return false;
        
        for(int i = 0; i < nums.size(); i++){
            rem = nums[i] % k;
            if(m.find(rem) == m.end()){
                m[rem] = 1;
            }
            else{
                m[rem]++;
            }
        }
        
        for(auto i: m){
            if((k - i.first) % k == i.first){
                if(i.second % 2 != 0) return false;
            }
            else{
                if(m.find(k - i.first) == m.end()) return false;
                else if(m[k - i.first] != i.second) return false;
            }
        }
        
        return true;
    }
};