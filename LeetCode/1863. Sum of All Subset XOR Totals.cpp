// DATE: 20-MAY-2024
// Question URL: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

// Question: 1863. Sum of All Subset XOR Totals
// Description: The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

//              For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
//              Given an array nums, return the sum of all XOR totals for every subset of nums. 

//              Note: Subsets with the same elements should be counted multiple times.

//              An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
// Approach: 1. Generate all subsets using bit manipulations then make sum of XOR of all elements of array at set bits positions of each number.

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0, _xor = 0;

        for(int i = 0; i < (1 << nums.size()); i++){
            _xor = 0;
            for(int j = 0; j <= log2(i); j++){
                if(i & (1 << j)){
                    _xor = _xor ^ nums[j];
                }
            }

            ans = ans + _xor;
        }

        return ans;
    }
};