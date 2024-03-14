// DATE: 14-MAR-2024
// Question URL: https://leetcode.com/problems/binary-subarrays-with-sum/description/

// Question: 930. Binary Subarrays With Sum
// Description: Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

//				A subarray is a contiguous part of the array.
// Approach: 1. Have a window which contains goal number of 1s. Now have a left and right counter stating left and right width before and after window. Then ans = ans + left*right.

func numSubarraysWithSum(nums []int, goal int) int {
	next := make([]int, len(nums))
	p1, p2, ans, c, left, right := 0, 0, 0, 0, 1, 1

	next[len(nums)-1] = -1
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i+1] == 1 {
			next[i] = 1
		} else if nums[i+1] == 0 {
			if next[i+1] == -1 {
				next[i] = -1
			} else {
				next[i] = next[i+1] + 1
			}
		}
	}

	if goal == 0 {
		for p1 < len(nums) {
			for p1 < len(nums) && nums[p1] != 0 {
				p1++
			}
			p2 = p1
			for p2 < len(nums) && nums[p2] != 1 {
				p2++
			}
			ans += (p2 - p1) * (p2 - p1 + 1) / 2
			p1 = p2 + 1
		}
	} else {
		for p1 < len(nums) && nums[p1] == 0 {
			left++
			p1++
		}
		p2 = p1
		for p2 < len(nums) {
			if c < goal && nums[p2] == 1 {
				c++
			}

			if c == goal {
				if next[p2] == -1 {
					right = len(nums) - p2
				} else {
					right = next[p2]
				}
				ans = ans + left*right

				if next[p1] == -1 || next[p2] == -1 {
					break
				}
				left = next[p1]
				p1 = p1 + next[p1]
				p2 = p2 + next[p2]
			} else {
				p2++
			}
		}
	}

	return ans
}