// DATE: 29-MAR-2024
// Question URL: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

// Question: 2958. Length of Longest Subarray With at Most K Frequency
// Description: You are given an integer array nums and a positive integer k.

//				Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

//				A subarray is a contiguous sequence of elements within an array.

// Approach: 1. Code is Self Explanatory.

func countSubarrays(nums []int, k int) int64 {
	_max, idxs := 0, make([]int, 0)

	for _, num := range nums {
		if num > _max {
			_max = num
		}
	}

	for idx, num := range nums {
		if num == _max {
			idxs = append(idxs, idx)
		}
	}

	p1, p2 := 0, k-1
	var ans int64 = 0

	for p2 < len(idxs) {
		if p1 == 0 {
			ans = ans + (int64)((idxs[p1]+1)*(len(nums)-idxs[p2]))
		} else {
			ans = ans + (int64)((idxs[p1]-idxs[p1-1])*(len(nums)-idxs[p2]))
		}

		p1++
		p2++
	}

	return ans
}