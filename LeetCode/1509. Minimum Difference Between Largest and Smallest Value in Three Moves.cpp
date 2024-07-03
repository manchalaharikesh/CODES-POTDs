// DATE: 03-JUL-2024
// Question URL: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

// Question: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// Description: You are given an integer array nums.

//              In one move, you can choose one element of nums and change it to any value.

//              Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

// Approach: 1. For any array with a size of 3 or less, all elements can be made equal, resulting in a minimum difference between the smallest and largest elements of zero.

//              For arrays with more than 3 elements, we need to choose up to 3 elements and modify them to minimize the difference between the smallest and largest elements.

//              To achieve this, we first sort the array in non-decreasing order. Then, we take a window of size 3 and, for each window, assume we modify those elements. Since the array is sorted, we can easily access the minimum and maximum elements within the rest of the array (excluding the window). We calculate the difference for each window and update our answer with the minimum difference found.

//              Initially, the window is moved in a circular fashion to consider all possible combinations of three elements. However, for arrays with a size of at least 5, iterating through windows that include the middle-most elements (from index 1 to n-2) is redundant, as these windows do not change the minimum and maximum elements of the whole array. Thus, we can reduce the number of iterations to 4 specific windows as follows:

//              - Window covering indices [n-3, n-2, n-1]
//              - Window covering indices [n-2, n-1, 0]
//              - Window covering indices [n-1, 0, 1]
//              - Window covering indices [0, 1, 2]

//              For each of these 4 windows, we find the difference between the minimum and maximum elements of the rest of the array. Refer to the code for a better understanding and perform a dry run to see it in action..

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;

        sort(nums.begin(), nums.end());

        int i = 1, ans = INT_MAX;

        while(i <= 4){
            ans = min(ans, nums[n-i] - nums[4 - i]);
            i++;
        }

        return ans;
    }
};