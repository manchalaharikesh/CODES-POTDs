// DATE: 12-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/perfect-numbers3207/1
// Question: Perfect Number
// Description: For a given number N, find if it is a perfect number or not.
// Approach: 1. Find all factors and find their sum (TC: O(N)).
//           2. Use the two pointer approach over the factors (TC: O(sqrt(N))).

class Solution {
  public:
    int isPerfectNumber(long long N) {
        long long sum = 1;
        long long p1 = 2;
        long long p2 = N/p1;
        
        if(N == 1) return 0;
        
        while(p1 <= p2){
            if(N%p1 == 0){
                sum = sum + p1 + p2;
            }
            p1++;
            p2 = N/p1;
        }
        
        if(sum == N) return 1;
        return 0;
    }
};