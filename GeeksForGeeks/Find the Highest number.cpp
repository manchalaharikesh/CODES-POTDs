// DATE: 18-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1
// Question: Find the Highest number
// Description: Given an integer array a[] of size n, find the highest element of the array. The array will either be strictly increasing or strictly increasing and then strictly decreasing.

//              Note: a[i] != a[i+1]
// Approach: 1. Remember that the array is either strictly increasing or else strictly increasing followed by strictly decreasing.
//              Thus if array is strictly increasing then last element is our answer.
//              Otherwise using binary search we find the maximum element where maximum element is greater than its left and right element (and they exists for sure because the array is both increasing and decreasing).

class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        int n = a.size();
        
        // strictly increasing
        if(a[n-1] > a[n-2]) return a[n-1];
        
        int low = 0, high = n-1, mid;
        
        while(low <= high){
            mid = low + (high - low)/2;
            if(mid-1 >= 0 && a[mid-1] < a[mid] && mid+1 < n && a[mid] > a[mid+1]) break;
            else if(a[mid] < a[mid+1]) low = mid + 1;
            else if(a[mid] > a[mid+1]) high = mid - 1;
        }
        
        return a[mid];
    }
};