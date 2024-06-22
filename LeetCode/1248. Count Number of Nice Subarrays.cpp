// DATE: 22-JUN-2024
// Question URL: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// Question: 1248. Count Number of Nice Subarrays
// Description: Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

//              Return the number of nice sub-arrays.
// Approach: 1. The approach is a based on sliding window, where we look for left and right possible width of a subarray at each iteration to find the number of subarrays possible for same k odd elements.
//              e.g.: arr = 2 2 2 2 1 2 2 1 2 1 2, k = 2
//                                  i     j
//                          left = 5, right = 4
//                          count = left * right = 20 that are possible with 1s at (4, 7)
//                    arr = 2 2 2 2 1 2 2 1 2 1 2, k = 2 
//                                        i   j
//                          left = 3, right = 2
//                          count = left*right = 6 that are possible with 1s at (7, 9).
//              This is done by storing the idxs of odd numbers in a seperate vector and each time in oddIdxs we have our window as i to i+k.
//              To find the possible left and right width of each window please refer to code.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> oddIdxs;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%2 == 1) oddIdxs.push_back(i);
        }

        if(oddIdxs.size() < k) return 0;

        oddIdxs.push_back(nums.size());
        int left = 0, right = 0, ans = 0;

        for(int i = 0; i <= oddIdxs.size() - k - 1; i++){
            left = oddIdxs[i] - (i - 1 >= 0 ? oddIdxs[i-1] : -1);
            right = oddIdxs[i+k] - oddIdxs[i+k-1];

            ans = ans + left*right;
        }

        return ans;
    }
};