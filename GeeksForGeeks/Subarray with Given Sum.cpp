// DATE: 19-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

// Question: Subarray with Given Sum
// Description: For a given unsorted array of size 'N' and an integer s find the subarray whose sum of elements is equal to s. 
//              Return the subarray start and end as a 1-based indexing. 
//              If no such subarray is found return -1
// Approach: 1. Two Pointer Concept.

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int left = 0, right = -1;
        long long sum = 0;
        
        if(s == 0) return vector<int>({-1});
        
        while((left < n || right < n) && sum != s){
            if((sum < s) && (right < n-1)) sum += arr[++right];
            else if(sum > s) sum -= arr[left++];
            else break;
            
            if(left > right) right = left-1;
        }
        
        if(sum == s) return vector<int>({left+1, right+1});
        return vector<int>({-1});
    }
};