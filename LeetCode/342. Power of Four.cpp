// DATE: 23-OCT-2023
// Question URL: https://leetcode.com/problems/power-of-four/

// Question: 342. Power of Four
// Description: Given an integer n, return true if it is a power of four. Otherwise, return false.

//              An integer n is a power of four, if there exists an integer x such that n == 4^x.
// Approach: 1. Brute Force Method - Code is Self Explanatory.

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        return (n != 0) && (n % 4 == 0) ? isPowerOfFour(n/4) : false;
    }
};