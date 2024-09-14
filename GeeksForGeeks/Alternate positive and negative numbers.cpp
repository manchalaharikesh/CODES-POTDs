// DATE: 14-SEP-2024
// Question URL: https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
// Question: Alternate positive and negative numbers
// Description: Given an unsorted array arr containing both positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
//              Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

// Approach: 1. Have pos and neg elements into respective arrays and arrange them alternatively into arr again.

class Solution {
  public:

    void rearrange(vector<int> &arr) {
        int p1 = 0, p2 = 0;
        vector<int> pos, neg;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < 0){
                neg.push_back(arr[i]);
            }
            else{
                pos.push_back(arr[i]);
            }
        }
        
        for(int i = 0; i < arr.size();){
            if(p1 < pos.size()) arr[i++] = pos[p1++];
            if(p2 < neg.size()) arr[i++] = neg[p2++];
        }
    }
};