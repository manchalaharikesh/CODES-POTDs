// DATE: 20-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/rotate-bits4524/1
// Question: Rotate Bits
// Description: For a given integer N and D rotate bits of N to left by D and rotate bits of N to right by D. Return the results in their decimal representation.
// Approach: 1. As it is 16 bit we do for D bit rotation and 16-D bit rotation. But, as integers are 32 bit we need the result to be restricted to it so make & with 65535 (as it is all set bits).

class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            d = d % 16;
            vector<int> v;
            
            v.push_back(((n << d) | (n >> (16-d))) & 65535);
            v.push_back(((n >> d) | (n << (16-d))) & 65535);
            return v;
        }
};