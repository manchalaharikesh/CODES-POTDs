// DATE: 11-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1
// Question: Lucky Numbers
// Description: For a given number N find the lucky number from 1 to N.
// Approach: 1. Recursive approach code is self explanatory (Didn't remember the approach 😝).

class Solution{
public:
    bool isLucky(int n) {
        return solve(n, 2);
    }
    
    bool solve(int n, int k){
        if(n < k) return true;
        else if(n % k == 0) return false;
        return solve(n - n/k, k + 1);
    }
};