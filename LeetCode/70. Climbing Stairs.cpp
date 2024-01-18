// DATE: 18-JAN-2024
// Question URL: https://leetcode.com/problems/climbing-stairs/description/

// Question: 70. Climbing Stairs
// Description: You are climbing a staircase. It takes n steps to reach the top.

//              Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Approach: 1. It is numOfWays(ith step) = numOfWays(i-1th step) + numOfWays(i-2th step). This recursive tree on optimization gives a fibonacci series.

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 2, c = 0;

        if(n == 1) return a;
        else if(n == 2) return b;

        while(n > 2){
            c = a + b;
            a = b;
            b = c;
            n--;
        }

        return c;
    }
};