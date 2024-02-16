// DATE: 17-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

// Question: Does array represent Heap
// Description: Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.
// Approach: 1. For value at index i arr[i] must be greater than value at index 2*i+1 and 2*i+2.

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        for(int i = 0; i < n; i++){
            if(2*i+1 < n && arr[i] < arr[2*i+1]) return false;
            if(2*i+2 < n && arr[i] < arr[2*i+2]) return false;
        }
        
        return true;
    }
};