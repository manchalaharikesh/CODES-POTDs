// DATE: 18-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1
// Question: Two Repeated Elements
// Description: You are given an integer n and an integer array arr of size n+2. All elements of the array are in the range from 1 to n. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
//              Note: Return the numbers in their order of appearing twice. So, if X and Y are the repeating numbers, and X's second appearance comes before second appearance of Y, then the order should be (X, Y).
// Approach: 1. Code is Self-Explanatory.

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        int num;
        vector<int> v;
        for(int i = 0; i < n+2; i++){
            num = abs(arr[i]);
            if(arr[num-1] < 0) v.push_back(num);
            else arr[num-1] = -arr[num-1];
        }
        
        return v;
    }
};