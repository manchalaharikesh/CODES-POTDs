// DATE: 19-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1
// Question: Find the closest number
// Description: Given a sorted array arr[] of positive integers. The task is to find the closest value in the array to the given number k. The array may contain duplicate values.

//              Note: If the difference with k is the same for two values in the array return the greater value.
// Approach: 1. Use binary search to find the number that is closest to k. Code is Self-Explanatory.

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int low = 0, high = n-1, mid;
        int diff = INT_MAX, ans = -1;
        
        while(low <= high){
            mid = low + (high - low)/2;
            
            if(diff > abs(arr[mid] - k)){
                diff = abs(arr[mid] - k);
                ans = arr[mid];
            }
            else if(diff == abs(arr[mid] - k)){
                ans = max(ans, arr[mid]);
            }
            
            if(arr[mid] == k) break;
            else if(arr[mid] > k) high = mid - 1;
            else low = mid + 1;
        }
        
        return ans;
    } 
};