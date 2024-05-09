// DATE: 09-MAY-2024
// Question URL: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

// Question: 3075. Maximize Happiness of Selected Children
// Description: You are given an array happiness of length n, and a positive integer k.

//				There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

//				In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

//				Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

// Approach: 1. Sort the happiness, then pick atmost k largest elements from back until ith element - (i-1) > 0 and add ith element - (i-1) to ans.

import "sort"

func maximumHappinessSum(happiness []int, k int) int64 {
	sort.Ints(happiness)
	var ans int64 = 0
	d := 0

	for i := len(happiness) - 1; i >= len(happiness)-k; i-- {
		if happiness[i]-d <= 0 {
			break
		}
		ans = ans + int64(happiness[i]-d)
		d++
	}

	return ans
}