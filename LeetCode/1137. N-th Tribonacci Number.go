// DATE: 24-APR-2024
// Question URL: https://leetcode.com/problems/n-th-tribonacci-number/description/

// Question: 1137. N-th Tribonacci Number
// Description: The Tribonacci sequence Tn is defined as follows:

//				T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

//				Given n, return the value of Tn.
// Approach: 1. Brute Force Code is Self-Explanatory.

func tribonacci(n int) int {
	if n == 0 {
		return 0
	} else if n == 1 {
		return 1
	} else if n == 2 {
		return 1
	}

	a, b, c, d, i := 0, 1, 1, 0, 0

	for i < n-2 {
		d = a + b + c
		a = b
		b = c
		c = d
		i++
	}

	return d
}