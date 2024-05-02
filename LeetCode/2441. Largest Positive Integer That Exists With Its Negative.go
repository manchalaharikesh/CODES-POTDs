// DATE: 02-MAY-2024
// Question URL: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

// Question: 2441. Largest Positive Integer That Exists With Its Negative
// Description: Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

//				Return the positive integer k. If there is no such integer, return -1.
// Approach: 1. Sort the integers, then we have a two pointer approach. Code is Self-Explanatory.

func findMaxK(nums []int) int {
	p1, p2, ans := 0, len(nums)-1, -1

	sort.Ints(nums)

	for p1 <= p2 {
		if nums[p1] > 0 || nums[p2] < 0 {
			break
		}

		if -nums[p1] == nums[p2] {
			ans = nums[p2]
			break
		} else if -nums[p1] > nums[p2] {
			p1++
		} else {
			p2--
		}
	}

	return ans
}