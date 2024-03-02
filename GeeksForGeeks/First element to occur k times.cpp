// DATE: 02-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1
// Question: First element to occur k times
// Description: Given an array of n integers. Find the first element that occurs atleast k number of times.
// Approach: 1. Store frequencies in hashmap.

class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        map<int, int> m;
        
        for(int i = 0; i < n; i++){
            m[a[i]]++;
            if(m[a[i]] == k) return a[i];
        }
        
        return -1;
    }
};