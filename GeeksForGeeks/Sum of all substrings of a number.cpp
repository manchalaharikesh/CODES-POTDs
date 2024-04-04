// DATE: 04-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
// Question: Sum of all substrings of a number
// Description: Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
//              As the answer will be large, return answer modulo 109+7. 

//              Note: The number may have leading zeros.
// Approach: 1. At dp[i] we store the sum of all the substrings that includes ith character.

class Solution
{
    public:
    long long sumSubstrings(string s){
        vector<long long> dp(s.size());
        long long ans = 0, mod = 1000000007;
        
        dp[0] = s[0] - '0';
        ans = dp[0];
        
        for(int i = 1; i < s.size(); i++){
            dp[i] = ((dp[i-1] % mod * 10) % mod) + (i+1)*(s[i] - '0');
            ans = (ans + dp[i]) % mod;
        }
        
        return ans;
    }
};