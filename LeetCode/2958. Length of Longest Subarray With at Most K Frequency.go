// DATE: 28-MAR-2024
// Question URL: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

// Question: 2958. Length of Longest Subarray With at Most K Frequency
// Description: You are given an integer array nums and an integer k.

//				The frequency of an element x is the number of times it occurs in an array.

//				An array is called good if the frequency of each element in this array is less than or equal to k.

//				Return the length of the longest good subarray of nums.

//				A subarray is a contiguous non-empty sequence of elements within an array.
// Approach: 1. Sliding Window + HashMap Code is Self-Explanatory.

func maxSubarrayLength(nums []int, k int) int {
	m := make(map[int]int)
	p1, p2, ans := 0, 0, 0

	for p2 < len(nums) {
		f, ok := m[nums[p2]]
		if !ok || f < k {
			m[nums[p2]]++
		} else {
			for nums[p1] != nums[p2] {
				m[nums[p1]]--
				p1++
			}
			m[nums[p1]]--
			p1++
			m[nums[p2]]++
		}

		ans = max(ans, p2-p1+1)
		p2++
	}

	return ans
}