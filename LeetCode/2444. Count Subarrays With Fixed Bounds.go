// DATE: 01-APR-2024
// Question URL: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

// Question: 2444. Count Subarrays With Fixed Bounds
// Description: You are given an integer array nums and two integers minK and maxK.

//				A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

//				The minimum value in the subarray is equal to minK.
//				The maximum value in the subarray is equal to maxK.
//				Return the number of fixed-bound subarrays.

//				A subarray is a contiguous part of an array.
// Approach: 1. At every element find the subarray with min length and max length. And difference is the no.of subarray that include the current element. Repeat it for every element.

func countSubarrays(nums []int, minK int, maxK int) int64 {
	m := make(map[int]int)
	p1, p2, _min, _max, min_sat := 0, 0, false, false, make([]int, len(nums))
	var ans int64 = 0

	for i := range min_sat {
		min_sat[i] = -1
	}

	for p2 < len(nums) {
		m[nums[p2]]++

		if nums[p2] == minK {
			_min = true
		}
		if nums[p2] == maxK {
			_max = true
		}

		if nums[p2] < minK || nums[p2] > maxK {
			for p1 < p2 {
				m[nums[p1]]--
				p1++
			}
			p1 = p2 + 1
			_min = false
			_max = false
		}

		for _min && _max {
			min_sat[p1] = p2
			m[nums[p1]]--

			if m[nums[p1]] == 0 {
				if nums[p1] == minK {
					_min = false
				}
				if nums[p1] == maxK {
					_max = false
				}
			}
			p1++
		}

		p2++
	}

	// fmt.Println(min_sat)
	p1, p2 = 0, 0

	for p2 < len(nums) {
		if nums[p2] < minK || nums[p2] > maxK {
			for p1 < p2 && min_sat[p1] != -1 {
				ans = ans + (int64)(p2-min_sat[p1])
				p1++
			}
			p2++
			p1 = p2
		} else {
			p2++
		}
	}

	for p1 < p2 && min_sat[p1] != -1 {
		ans = ans + (int64)(p2-min_sat[p1])
		p1++
	}

	return ans
}