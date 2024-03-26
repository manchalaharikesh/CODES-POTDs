// DATE: 26-MAR-2024
// Question URL: https://leetcode.com/problems/first-missing-positive/description/

// Question: 41. First Missing Positive
// Description: Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

//				You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
// Approach: 1. -ve and numbers > len(nums) are not of use in answer so mark them 0 in nums. For every element in nums mark element-1 as -ve (handle duplicates).
//			 Then if at any place element >= 0 ans is idx+1 otherwise 1 to len(nums) all are present to ans is len(nums)+1.

func firstMissingPositive(nums []int) int {
	for idx, num := range nums {
		if num < 0 || num > len(nums) {
			nums[idx] = 0
		}
	}

	for _, num := range nums {
		if num == 0 {
			continue
		} else if num < 0 {
			num = -num
		}

		if nums[num-1] == 0 {
			nums[num-1] = -num
		} else if nums[num-1] > 0 {
			nums[num-1] = -nums[num-1]
		}
	}

	for idx, num := range nums {
		if num >= 0 {
			return idx + 1
		}
	}

	return len(nums) + 1
}