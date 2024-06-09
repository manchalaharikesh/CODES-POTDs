// DATE: 09-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1
// Question: Convert array into Zig-Zag fashion
// Description: Given an array arr of distinct elements of size n, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 

//              arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 
//              Note: Modify the given arr[] only, If your transformation is correct, the output will be 1 else the output will be 0. 
// Approach: 1. Iterate from [0, arr.size()-1], when i is even index we need to ensure arr[i] < arr[i+1] otherwise swap.
//              if i is odd we need to ensure arr[i] > arr[i+1] otherwise swap.

class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        int temp;
        for(int i = 0; i < n-1; i++){
            if(i % 2 == 0){
                if(arr[i] > arr[i+1]){
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
            else{
                if(arr[i] < arr[i+1]){
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
        }
    }
};