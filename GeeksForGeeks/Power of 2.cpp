// DATE: 18-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
// Question: Power of 2
// Description: For a given integer N, return true if N is a 2^x else return false.
// Approach: 1. Count set bits using TC: O(log(N)).

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        int c = 0;
        while(n != 0){
            c++;
            n = n & (n - 1);
        }
        
        return c == 1;
        
    }
};