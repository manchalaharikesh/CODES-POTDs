// DATE: 17-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1
// Question: Find Pair Given Difference
// Description: Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.
// Approach: 1. Sort the given arr elements, then for i in (0, n) ele = x + arr[i], then find ele in (i+1 to n) using binary search.

class Solution {
  public:
    bool binarySearch(vector<int>& arr, int low, int high, int ele){
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(arr[mid] == ele) return true;
            else if(arr[mid] < ele) low = mid + 1;
            else high = mid - 1;
        }
        
        return false;
    }
    int findPair(int n, int x, vector<int> &arr) {
        int p1 = 0, p2 = n-1;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++){
            if(binarySearch(arr, i+1, n-1, x + arr[i])) return 1;
        }
        
        return -1;
    }
};