// DATE: 02-APR-2024
// Question URL: https://leetcode.com/problems/isomorphic-strings/description/

// Question: 205. Isomorphic Strings
// Description: Given two strings s and t, determine if they are isomorphic.

//				Two strings s and t are isomorphic if the characters in s can be replaced to get t.

//				All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Approach: 1. Code is Self-Explanatory.

func isIsomorphic(s string, t string) bool {
	mapped := make(map[byte]byte)
	taken := make(map[byte]byte)

	for i := range s {
		_, isMapped := mapped[s[i]]
		_, isTaken := taken[t[i]]
		if !isMapped && !isTaken {
			mapped[s[i]] = t[i]
			taken[t[i]] = s[i]
		} else if (isMapped && mapped[s[i]] != t[i]) || (isTaken && taken[t[i]] != s[i]) {
			return false
		}
	}

	return true
}