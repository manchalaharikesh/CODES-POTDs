// DATE: 15-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/grinding-geek/1
// Question: Grinding Geek
// Description: GeeksforGeeks has introduced a special offer where you can enroll in any course, and if you manage to complete 90% of the course within 90 days, you will receive a refund of 90%.

//              Geek was fascinated by this offer. This offer was valid for only n days, and each day a new course was available for purchase. Geek decided that if he bought a course on some day, he will complete that course on the same day itself and redeem floor[90% of cost of the course] amount back. Find the maximum number of courses that Geek can complete in those n days if he had total amount initially.

//              Note: On any day, Geek can only buy the new course that was made available for purchase that day.
// Approach: 1. In the dp array we have at dp[idx][balance] we have the maximum number of courses that can be possible from idx to n with in balance of amount.

class Solution{
    public:
    int solve(int idx, int n, vector<int>& cost, int balance, vector<vector<int>>& dp){
        if(idx == n || balance == 0) return 0;
        else if(dp[idx][balance] != 0) return dp[idx][balance];
        
        int inclusive = 0, exclusive = 0;
        if(balance >= cost[idx]){
            inclusive = 1 + solve(idx + 1, n, cost, (int)(balance-0.1*cost[idx]), dp);
        }
        exclusive = solve(idx + 1, n, cost, balance, dp);
        
        dp[idx][balance] = max(inclusive, exclusive);
        
        return dp[idx][balance];
    }
    
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n+1, vector<int>(total+1, 0));
        
        return solve(0, n, cost, total, dp);
    }
};