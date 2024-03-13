// DATE: 13-MAR-2024
// Question URL: https://leetcode.com/problems/find-the-pivot-integer/description/

// Question: 2485. Find the Pivot Integer
// Description: Given a positive integer n, find the pivot integer x such that:

//				The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
//				Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

// Approach: 1. Implement Binary Search on finding the pivot element.

func pivotInteger(n int) int {
	sum, left_sum := n*(n+1)/2, 0
	low, high, mid := 1, n, 0

	for low <= high {
		mid = (low + high) / 2
		left_sum = mid * (mid + 1) / 2

		if left_sum == sum-left_sum+mid {
			return mid
		} else {
			if left_sum > sum-left_sum+mid {
				high = mid - 1
			} else {
				low = mid + 1
			}
		}
	}

	return -1
}