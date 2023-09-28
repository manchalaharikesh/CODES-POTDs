// DATE: 28-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1
// Question: Wave Array
// Description: For a given sorted array convert it into an array such that arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] and so on.
// Approach: 1. Two pointers swap arr[p1] and arr[p2].

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        int p1 = 0, p2 = 1;
        
        while(p2 < n){
            swap(arr[p1], arr[p2]);
            p1 += 2;
            p2 += 2;
        }
    }
    
    void swap(int& x, int& y){
        int temp = x;
        x = y;
        y = temp;
    }
};