// DATE: 17-JUN-2024
// Question URL: https://leetcode.com/problems/sum-of-square-numbers/description/

// Question: 633. Sum of Square Numbers
// Description: Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
// Approach: 1. The current solution is a two pointer approach where it is evident that the values a and b must lie in the range [0, sqrt(c)].
//              Thus we start a pointer i from 0 and another pointer j from sqrt(c), then 
//              if i*i + j*j > c we need to decrease sum so dec j (we decrease only j not i because for some value <= i and some value >= j already we might faced sum < c so keeping j same and dec i again cause sum < c problem), 
//              else if i*i + j*j < c we need to increase sum to inc i (we increase only i not j because for some value <= i and some value >= j already we might faced sum > c so keeping i same and inc j will again cause sum > c problem), 
//              otherwise we found ans.
//              We repeat above 3 steps in a valid bound for i, j i.e.m i <= j.

class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 1, j = sqrt(c);

        if(j*j == c) return true;
        
        long sum = 0;

        while(i <= j){
            sum = i*i + j*j;
            if(sum == c) return true;
            else if(sum > c) j--;
            else i++;
        }

        return false;
    }
};