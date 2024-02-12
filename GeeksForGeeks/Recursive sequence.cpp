// DATE: 12-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/recursive-sequence1611/1
// Question: Recursive sequence
// Description: A function F is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... upto n terms (look at the examples for better clarity). Given an integer n, determine the F(n).

//              Note: As the answer can be very large, return the answer modulo 10^9+7.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution{
public:
    long long sequence(int n){
        long long ans = 0, mul = 1, temp = 1, mod = 1000000007;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i+1; j++){
                mul = (mul % mod)*(temp % mod);
                temp++;
            }
            ans = (ans + mul) % mod;
            mul = 1;
        }
        
        return ans;
    }
};