// DATE: 01-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/peak-element/1

// Question: Peak element
// Description: Given an 0-indexed array of integers arr[] of size n, find its peak element. An element is considered to be peak if it's value is greater than or equal to the values of its adjacent elements (if they exist). The array is guaranteed to be in ascending order before the peak element and in descending order after it.

//              Note: The output will be 1 if the index returned by your function is correct; otherwise, it will be 0.
// Approach: 1. Code is Self-Explanatory.

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        
        if(n==1) return 0;
        
        for(int i = 0; i < n; i++){
            if(i==0 && arr[i] >= arr[i+1]){
                return i;
            }
            else if(i==n-1 && arr[i] >= arr[i-1]){
                return i;
            }
            else if(i!=0 && i!=n-1 && arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
                return i;
            }
        }
        return -1;
    }
};