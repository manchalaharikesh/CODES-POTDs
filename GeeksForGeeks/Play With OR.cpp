// DATE: 27-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/play-with-or5515/1
// Question: Play With OR
// Description: You are given an array arr[] of length n, you have to re-construct the same array arr[] in-place. The arr[i] after reconstruction will become arr[i] OR arr[i+1], where OR is bitwise or. If for some i, i+1 does not exists, then do not change arr[i].
// Approach: 1. Code is Self-Explanatory.

int* game_with_number(int arr[], int n)
{
    for(int i = 0; i < n-1; i++){
        arr[i] = arr[i] | arr[i+1];
    }
    
    return arr;
}