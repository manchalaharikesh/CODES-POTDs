// DATE: 19-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1

// Question: First Set Bit
// Description: For a given integer N find the first set bit in N.
// Approach: 1. self explanatory TC: O(log(N)).

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        unsigned int c = 1;
        
        if(n == 0) return 0;
        
        while(n > 0){
            if(n & 1) return c;
            c++;
            n >>= 1;
        }
        
        return c;
    }
};