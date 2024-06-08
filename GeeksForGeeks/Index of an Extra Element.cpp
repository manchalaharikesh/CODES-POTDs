// DATE: 08-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1
// Question: Index of an Extra Element
// Description: You have given two sorted arrays arr1[] & arr2[] of distinct elements. The first array has one element extra added in between. Return the index of the extra element.

//              Note: 0-based indexing is followed.
// Approach: 1. Lets say there is a new element inserted into arr1 at kth index then until k-1 all elements will be equal in arr1 and arr2 (arr1[0:k] == arr2[0:k]).
//              Now we implement binary search in such a way if arr1[mid] == arr2[mid] it means extra element is not inserted in left subarray of mid so we move to right.
//              If arr1[mid] != arr2[mid] then arr1[mid] might be the answer or else the answer is in the [left, mid] subarray. We continue our search by storing the current arr1[mid] in the ans.
//              If we further able to repeat above step ans will be similarly updated until we reach the point where the new element has been intserted (i.e., until the point k where we cant move to the left subarray further).

class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        if(arr1[n-1] != arr2[n-2]) return n-1;
        
        int low = 0, high = n-2, mid, ans;
        
        while(low <= high){
            mid = low + (high - low)/2;
            
            if(arr1[mid] == arr2[mid]) low = mid + 1;
            else{ 
                high = mid - 1;
                ans = mid;
            }
        }
        
        return ans;
    }
};