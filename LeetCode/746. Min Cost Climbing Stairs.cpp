// DATE: 13-OCT-2023
// Question URL: https://leetcode.com/problems/min-cost-climbing-stairs/

// Question: 746. Min Cost Climbing Stairs
// Description: You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

//              You can either start from the step with index 0, or the step with index 1.

//              Return the minimum cost to reach the top of the floor.
// Approach: 1. At dp[i] we store the min cost to either dp[i+1] or dp[i+2].

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for(int i = n-3; i >= 0; i--){
            cost[i] = cost[i] + min(cost[i+1], cost[i+2]);
        }

        return min(cost[0], cost[1]);
    }
};