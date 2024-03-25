// DATE: 25-MAR-2024
// Question URL: https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Question: 442. Find All Duplicates in an Array
// Description: Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

//				You must write an algorithm that runs in O(n) time and uses only constant extra space.
// Approach: 1. At every num mark nums[num-1] as -ve. Then if at any occurence of num if nums[num-1] is already -ve it means it is a repetition.

func findDuplicates(nums []int) []int {
	ans := make([]int, 0)

	for _, num := range nums {
		if num < 0 {
			num = -num
		}

		if nums[num-1] < 0 {
			ans = append(ans, num)
		} else {
			nums[num-1] = -nums[num-1]
		}
	}

	return ans
}