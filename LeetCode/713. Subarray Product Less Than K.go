// DATE: 27-MAR-2024
// Question URL: https://leetcode.com/problems/subarray-product-less-than-k/description/

// Question: 713. Subarray Product Less Than K
// Description: Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
// Approach: 1. Sliding Window - Code is Self-Explanatory.

func numSubarrayProductLessThanK(nums []int, k int) int {
	if k == 0 {
		return 0
	}

	p1, p2, mul, ans, t1, t2 := 0, 0, 1, 0, 0, 0

	for p2 < len(nums) {
		t1 = mul * nums[p2]
		if t1 < k {
			mul = t1
			p2++
		} else {
			t2 = t1
			for p1 < p2 && t2 >= k {
				ans = ans + (p2 - p1)
				mul = mul / nums[p1]
				t2 = t2 / nums[p1]
				p1++
			}

			if p1 == p2 && nums[p2] >= k {
				p1++
				p2++
			}
		}
	}

	if p1 < len(nums) {
		ans = ans + (p2-p1)*(p2-p1+1)/2
	}

	return ans
}