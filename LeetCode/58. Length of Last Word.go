// DATE: 01-APR-2024
// Question URL: https://leetcode.com/problems/length-of-last-word/description/

// Question: 58. Length of Last Word
// Description: Given a string s consisting of words and spaces, return the length of the last word in the string.

//				A word is a maximal substring consisting of non-space characters only.
// Approach: 1. Code is Self-Explanatory.

func lengthOfLastWord(s string) int {
	length, c := len(s), 0

	if s[length-1] == ' ' {
		for s[length-1] == ' ' {
			length--
		}
	}

	for i := length - 1; i >= 0 && s[i] != ' '; i-- {
		c++
	}

	return c
}