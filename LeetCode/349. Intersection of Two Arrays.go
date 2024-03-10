// DATE: 10-MAR-2024
// Question URL: https://leetcode.com/problems/intersection-of-two-arrays/description/

// Question: 349. Intersection of Two Arrays
// Description: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
// Approach: 1. Code is Self-Explanatory.

func intersection(nums1 []int, nums2 []int) []int {
	flag := make([]int, 1001)
	ans := make([]int, 0)

	for _, num := range nums1 {
		if flag[num] == 0 {
			flag[num]++
		}
	}

	for _, num := range nums2 {
		if flag[num] == 1 {
			flag[num]++
		}
	}

	for idx, num := range flag {
		if num == 2 {
			ans = append(ans, idx)
		}
	}

	return ans
}