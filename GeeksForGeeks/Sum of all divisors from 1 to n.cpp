// DATE: 21-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
// Question: Sum of all divisors from 1 to n
// Description: Given a positive integer N., The task is to find the value of    \sum_{i=1}^{i=n} F(i)  where function F(i) for the number i is defined as the sum of all divisors of i.
// Approach: 1. From 1 to N an integer i can divide (N / i) integers.

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long ans = 0;
        
        for(int i = 1; i <= N; i++){
            ans += i*(N / i);
        }
        
        return ans;
    }
};