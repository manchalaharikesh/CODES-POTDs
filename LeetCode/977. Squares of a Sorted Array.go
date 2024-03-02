// DATE: 02-MAR-2024
// Question URL: https://leetcode.com/problems/squares-of-a-sorted-array/description/

// Question: 977. Squares of a Sorted Array
// Description: Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Approach: 1. Two Pointer concept to rearrange the elements of nums in such a way abs(nums[i]) is sorted. Then apply nums[i] = nums[i] * nums[i].

import "math"

func sortedSquares(nums []int) []int {
    p1, p2 := 0, len(nums)-1
    i := len(nums)-1
    ans := make([]int, len(nums))

    copy(ans, nums)

    for p1 <= p2 {
        if math.Abs(float64(nums[p1])) <= math.Abs(float64(nums[p2])) {
            ans[i] = nums[p2]
            p2--
        } else {
            ans[i] = nums[p1]
            p1++
        }
        
        i--;
    }

    for i := 0; i < len(nums); i++ {
        ans[i] = ans[i] * ans[i]
    }

    return ans
}