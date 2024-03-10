// DATE: 01-MAR-2024
// Question URL: https://leetcode.com/problems/maximum-odd-binary-number/description/

// Question: 2864. Maximum Odd Binary Number
// Description: You are given a binary string s that contains at least one '1'.

//				You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

//				Return a string representing the maximum odd binary number that can be created from the given combination.

//				Note that the resulting string can have leading zeros.
// Approach: 1. Brute-Force Code is Self-Explanatory.

func maximumOddBinaryNumber(s string) string {
	ones := 0
	var ans string

	for i := range s {
		if s[i] == '1' {
			ones++
		}
	}

	for i := 0; i < len(s)-1; i++ {
		if i < ones-1 {
			ans = ans + "1"
		} else {
			ans = ans + "0"
		}
	}
	ans = ans + "1"

	return ans
}