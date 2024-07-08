// DATE: 08-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
// Question: Search in Rotated Sorted Array
// Description: Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

//              Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.
//              Note:- 0-based indexing is followed & returns -1 if the key is not present.
// Approach: 1. We know that the array might be rotated, to find the target in this rotated arry by implementing binary search we need to find the partition where the rotated array starts so that we can implement binary search independently for both arrays.
//              Now to find the partition of the original and rotated array, we use binary search to find the position where arr[mid] >= arr[0] && arr[mid] > arr[mid+1]. This mid is the partition position.
//              Then we need to implement binary search in array [0, par] if key >= arr[0], else implement binary search in rotated array [par+1, arr.size()-1] if key < arr[0].
//              For all other edges cases please look into the code for better understanding.

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int par, low = 0, high = arr.size()-1, mid;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] >= arr[0]){
                if(mid+1 < arr.size() && arr[mid] > arr[mid+1]) break;
                else low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        par = mid;
        
        if(key >= arr[0]){
            low = 0;
            high = par;
        }
        else{
            low = par + 1;
            high = arr.size()-1;
        }
        
        while(low <= high){
            mid = low + (high - low) / 2;
            
            if(arr[mid] == key) return mid;
            else if(arr[mid] > key) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};