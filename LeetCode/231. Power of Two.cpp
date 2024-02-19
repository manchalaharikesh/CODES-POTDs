// DATE: 19-FEB-2024
// Question URL: https://leetcode.com/problems/power-of-two/description/

// Question: 231. Power of Two
// Description: Given an integer n, return true if it is a power of two. Otherwise, return false.

//              An integer n is a power of two, if there exists an integer x such that n == 2^x.
// Approach: 1. Check if there is only one set bit in the given number.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;

        while(n > 0){
            if(n & 1){
                n /= 2;
                break;
            }
            n /= 2;
        }

        return n == 0;
    }
};