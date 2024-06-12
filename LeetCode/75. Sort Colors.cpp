// DATE: 12-JUN-2024
// Question URL: https://leetcode.com/problems/sort-colors/description/

// Question: 75. Sort Colors
// Description: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

//              We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

//              You must solve this problem without using the library's sort function.
// Approach: 1. Code is Self-Explanatory.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] == 1) one++;
        }

        for(int i = 0; i < nums.size(); i++){
            if(zero){
                nums[i] = 0;
                zero--;
            }
            else if(one){
                nums[i] = 1;
                one--;
            }
            else{
                nums[i] = 2;
            }
        }
    }
};