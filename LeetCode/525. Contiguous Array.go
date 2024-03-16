// DATE: 16-MAR-2024
// Question URL: https://leetcode.com/problems/contiguous-array/description/

// Question: 525. Contiguous Array
// Description: Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// Approach: 1. For 0 add -1 else add 1. Store every sum in a map. If anytime same sum is occured (check in map) means we came across equal number of 0s and 1s. So update a ans variable accordingly.

func findMaxLength(nums []int) int {
	if len(nums) == 1 {
		return 0
	}

	m := make(map[int]int)
	ans, c := 0, 0

	for idx, num := range nums {
		if num == 0 {
			c--
		} else {
			c++
		}

		if c == 0 {
			ans = idx + 1
		} else if _, ok := m[c]; ok {
			ans = max(ans, idx-m[c])
		} else {
			m[c] = idx
		}
	}

	return ans
}