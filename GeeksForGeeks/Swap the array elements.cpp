// DATE: 04-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/need-some-change/1

// Question: Swap the array elements
// Description: Given an array arr of n positive integers. The task is to swap every ith element of the array with (i+2)th element.
// Approach: 1. Use two pointers two move incrementively starting at 0 and 2, and swap values at each iteration.

class Solution{
  public:
    void swapElements(int arr[], int n){
        int p1 = 0, p2 = 2;
        
        while(p2 < n){
            arr[p1] = arr[p1] + arr[p2];
            arr[p2] = arr[p1] - arr[p2];
            arr[p1] = arr[p1] - arr[p2];
            
            p1++;
            p2++;
        }
    }
};