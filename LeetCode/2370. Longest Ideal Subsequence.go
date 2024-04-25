// DATE: 25-APR-2024
// Question URL: https://leetcode.com/problems/longest-ideal-subsequence/description/

// Question: 2370. Longest Ideal Subsequence
// Description: You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

//				t is a subsequence of the string s.
//				The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
//				Return the length of the longest ideal string.

//				A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

//				Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.
// Approach: 1. For every s[i] look for characters in window of k that occured in s[0 to i-1] in the dp array. Then for each char in k window find the maximum length possible in dp which used to update dp[s[i] - 97].

func longestIdealString(s string, k int) int {
	dp := make([]int, 26)
	val := 0
	idx := 0
	ans := 0

	for i := range s {
		val = 0
		idx = int(s[i]) - 97
		// left
		for j := idx; j >= 0 && j >= idx-k; j-- {
			val = max(dp[j], val)
		}
		// right
		for j := idx; j <= idx+k && j < 26; j++ {
			val = max(dp[j], val)
		}

		dp[idx] = max(val+1, dp[idx])
		ans = max(ans, dp[idx])
	}

	return ans
}