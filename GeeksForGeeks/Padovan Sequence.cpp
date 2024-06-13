// DATE: 13-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/padovan-sequence2855/1

// Question: Padovan Sequence
// Description: Given a number n, find the nth number in the Padovan Sequence.

//              A Padovan Sequence is a sequence which is represented by the following recurrence relation
//              P(n) = P(n-2) + P(n-3)
//              P(0) = P(1) = P(2) = 1
//              Note: Since the output may be too large, compute the answer modulo 10^9+7.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution
{
    public:
    int padovanSequence(int n)
    {
        if(n <= 2) return 1;
        
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        
       for(int i = 3; i <= n; i++){
           dp[i] = (dp[i-2] + dp[i-3]) % 1000000007;
       }
       
       return dp[n];
    }
    
};