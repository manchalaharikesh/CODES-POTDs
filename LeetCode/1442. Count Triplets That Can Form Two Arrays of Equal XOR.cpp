// DATE: 30-MAY-2024
// Question URL: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

// Question: 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// Description: Given an array of integers arr.

//              We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

//              Let's define a and b as follows:

//              a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
//              b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
//              Note that ^ denotes the bitwise-xor operation.

//              Return the number of triplets (i, j and k) Where a == b.
// Approach: 1. Brute Force O(n^3) approach.

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int a = 0, b = 0, ans = 0;
        for(int i = 0; i < arr.size(); i++){
            a = 0;
            for(int j = i; j < arr.size(); j++){
                a = a ^ arr[j];
                b = 0;
                for(int k = j+1; k < arr.size(); k++){
                    b = b ^ arr[k];
                    if(a == b){ 
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};