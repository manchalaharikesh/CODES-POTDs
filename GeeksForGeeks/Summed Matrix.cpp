// DATE: 24-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/summed-matrix5834/1
// Question: Summed Matrix
// Description: A matrix is constructed of size n*n and given an integer ‘q’. The value at every cell of the matrix is given as, M(i,j) = i+j, where ‘M(i,j)' is the value of a cell, ‘i’ is the row number, and ‘j’ is the column number. Return the number of cells having value ‘q’.

//              Note: Assume, the array is in 1-based indexing.
// Approach: 1. Dry Run the code with any example given for better understanding.

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(q <= n+1) return q-1;
        else if(q <= n+n) return n+n-q+1;
        return 0;
    }
};