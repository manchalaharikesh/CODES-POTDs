// DATE: 24-MAR-2024
// Question URL: https://leetcode.com/problems/find-the-duplicate-number/

// Question: 287. Find the Duplicate Number
// Description: Given an array of N+1 size which has numbers only from 1 to N. There is a number present more than once. Find the number in linear time and constant space. Don't modify the array.
// Approach: 1. For a num[i] make the num[num[i]] to -ve in array. If ever found num[num[i]] is -ve return num[i].

func findDuplicate(nums []int) int {
	var x int

	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			x = nums[i]
		} else {
			x = -nums[i]
		}

		if nums[x] < 0 {
			break
		} else {
			nums[x] = -nums[x]
		}
	}

	return x
}