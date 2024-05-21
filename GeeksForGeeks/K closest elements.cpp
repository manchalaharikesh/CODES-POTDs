// DATE: 21-MAY-2024
// Question https://www.geeksforgeeks.org/problems/k-closest-elements3619/1
// Question: K closest elements
// Description: Given a sorted array in increasing order, arr[] of n integers, and a value x. Find the K closest elements to x in arr[].
//              Keep the following points in mind:

//              If x is present in the array, then it need not be considered.
//              If two elements have the same difference as x, the greater element is prioritized.
//              If sufficient elements are not present on the right side, take elements from the left and vice versa.
// Approach: 1. The things which needs to be specified in this question are the elements of the array are to be unique and also array is sorted.
//              Then we use binary search to find the stable element which has low absolute difference compared to its neighbours when compared with x.
//              Then using a two pointer concept we look for k nearest elements from this stable element.
//              All other edge cases are to be handled accordingly for better understanding refer to code.

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int low = 0, high = n-1, mid, left, right, c = 0;
        int p1, p2;
        vector<int> ans;
        
        while(low <= high){
            mid = low + (high-low)/2;
            if(mid-1 >= 0) left = abs(x - arr[mid-1]);
            else left = INT_MAX;
            
            if(mid+1 < n) right = abs(x - arr[mid+1]);
            else right = INT_MAX;
            
            if((left > abs(x-arr[mid]) && right > abs(x-arr[mid])) || abs(x-arr[mid]) == 0) break;
            else if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
        
        p1 = arr[mid] == x ? mid-1 : mid;
        p2 = arr[mid] == x ? mid+1 : mid;
        
        if(p1 == p2) p2++;
        
        while(c != k){
            left = p1 >= 0 ? abs(arr[p1] - x) : INT_MAX;
            right = p2 < n ? abs(arr[p2] - x) : INT_MAX;
            
            if(left >= right){
                ans.push_back(arr[p2]);
                p2++;
            }
            else{
                ans.push_back(arr[p1]);
                p1--;
            }
            c++;
        }
        
        return ans;
    }
};