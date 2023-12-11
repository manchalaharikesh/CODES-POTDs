// DATE: 11-DEC-2023
// Question URL: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// Question: Max Sum Subarray of size K
// Description: Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

//              NOTE*: A subarray is a contiguous part of any given array.
// Approach: 1. Make a sliding window appraoch of size k and store maximum sum into ans in each pass.

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long int ans = 0, sum = 0;
        
        for(int i = 0; i < N; i++){
            if(i < K){
                ans += Arr[i];
                sum += Arr[i];
                continue;
            }
            ans = max({ans, sum, sum - Arr[i-K] + Arr[i]});
            sum = sum - Arr[i-K] + Arr[i];
        }
        
        return ans;
    }
};