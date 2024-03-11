// DATE: 11-MAR-2024
// Question URL: https://leetcode.com/problems/custom-sort-string/description/

// Question: 791. Custom Sort String
// Description: You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

//				Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

//				Return any permutation of s that satisfies this property.
// Approach: 1. Store chars of order in a map with values as idx of occurence (as their index shows their importance). Now sort string s with comparing chars imp in the map.

func customSortString(order string, s string) string {
	imp := make([]int, 26)

	for idx, ch := range order {
		imp[ch-'a'] = idx
	}

	chars := []rune(s)

	sort.Slice(chars, func(i int, j int) bool { return imp[int(chars[i])-97] < imp[int(chars[j])-97] })

	return string(chars)
}