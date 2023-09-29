// DATE: 29-SEP-2023
// Question URL: https://leetcode.com/problems/monotonic-array/

// Question: 896. Monotonic Array
// Description: Given an array arr return true if it is either monotonically increasing or decreasing, return false otherwise.
// Approach: 1. Code is Self Explanatory.

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1) return true;

        bool status = true;

        // monotonic increasing
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                status = false;
                break;
            }
        }

        if(status) return true;
        status = true;

        // monotonic decreasing
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                status = false;
                break;
            }
        }

        return status;
    }
};