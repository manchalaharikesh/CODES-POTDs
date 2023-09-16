// DATE: 16-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/
// Question: Count Number of Hops
// Description: For a given integer N, find the number of ways to reach the Nth step. If you are allowed to make 1, 2 or 3 jumps from ith step.
// Approach: 1. Make a backtracking approach to calculate all possibilities.
//           2. Make a dp approach where the dp[i] state is the ways to cover i distance to reach Nth step.
//           3. To decrease dp memory we can restrict its size to 4. Make a dp approach where the dp[i%4] state is the ways to cover i distance to reach Nth step. 

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long dp[4] = {0, 1, 2, 4};
        long long mod = 1000000007;
        
        for(int i = 4; i <= n; i++){
            dp[i%4] = (dp[(i+1)%4] + dp[(i+2)%4] + dp[(i+3)%4]) % mod;
        }
        
        return dp[n%4];
    }
};
