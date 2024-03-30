// DATE: 30-MAR-2024
// Question URL: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

// Question: 992. Subarrays with K Different Integers
// Description: Given an integer array nums and an integer k, return the number of good subarrays of nums.

//				A good array is an array where the number of different integers in that array is exactly k.

//				For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//				A subarray is a contiguous part of an array.
// Approach: 1. For every element find the min subarray and max subarray with k distinct elements. For that element the no.of subarrays is maxSubarrays - minSubarrays. And the ans is the sum of count of all elements.

func subarraysWithKDistinct(nums []int, k int) int {
	m := make(map[int]int)
	mins := make([]int, len(nums))

	p1, p2, c, n := 0, 0, 0, len(nums)

	for i := range mins {
		mins[i] = n
	}

	// find min len subarray
	for p2 < n {
		if _, ok := m[nums[p2]]; !ok {
			m[nums[p2]]++
			c++
		} else {
			m[nums[p2]]++
		}

		for c == k {
			mins[p1] = p2
			m[nums[p1]]--

			if m[nums[p1]] == 0 {
				delete(m, nums[p1])
				c--
			}
			p1++
		}
		p2++
	}

	// find max len subarray
	p1, p2, c = 0, 0, 0
	m = make(map[int]int)
	ans := 0

	for p2 < n {
		if _, ok := m[nums[p2]]; !ok {
			for c == k {
				ans = ans + (p2 - mins[p1])
				m[nums[p1]]--

				if m[nums[p1]] == 0 {
					delete(m, nums[p1])
					c--
				}
				p1++
			}

			m[nums[p2]]++
			c++
		} else {
			m[nums[p2]]++
		}
		p2++
	}

	for c == k {
		ans = ans + (p2 - mins[p1])
		m[nums[p1]]--

		if m[nums[p1]] == 0 {
			delete(m, nums[p1])
			c--
		}
		p1++
	}

	return ans
}