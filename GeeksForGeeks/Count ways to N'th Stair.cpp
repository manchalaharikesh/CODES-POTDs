// DATE: 06-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
// Question: Count ways to N'th Stair
// Description: There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        return 1 + n/2;
    }
};