// DATE: 23-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1
// Question: Fibonacci series up to Nth term
// Description: You are given an integer n, return the fibonacci series till the nth(0-based indexing) term. Since the terms can become very large return the terms modulo 10^9+7.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    vector<int> Series(int n) {
        int a = 0, b = 1, c = 0;
        vector<int> ans{0, 1};
        
        if(n == 0){
            return vector<int>{0};
        }
        else if(n == 1){
            return ans;
        }
        
        for(int i = 0; i < n-1; i++){
            c = (a + b) % 1000000007;
            ans.push_back(c);
            a = b;
            b = c;
        }
        
        return ans;
    }
};