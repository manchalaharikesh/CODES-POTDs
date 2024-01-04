// DATE: 04-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
// Question: Find element occuring once when all other are present thrice
// Description: Given an array of integers arr[] of length N, every element appears thrice except for one which occurs once.
//              Find that element which occurs once.
// Approach: 1. Use bit manipulations to count the number of elements with ith bit as set and if the count % 3 == 1 the result has ith bit set.

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        int ans = 0, i = 0, c = 0, ver;
        int _max = *max_element(arr, arr + N);
        
        while(i < 32){
            ver = 1 << i;
            for(int j = 0; j < N; j++){
                if(ver & arr[j]){
                    c++;
                }
            }
            if(c % 3 == 1) ans = ans | ver;
            c = 0;
            i++;
        }
        
        return ans;
    }
};