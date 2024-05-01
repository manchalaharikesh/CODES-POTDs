// DATE: 01-MAY-2024
// Question URL: https://leetcode.com/problems/reverse-prefix-of-word/description/

// Question: 2000. Reverse Prefix of Word
// Description: Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

//				For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
//				Return the resulting string.
// Approach: 1. Brute Force Code is Self-Explanatory.

func reversePrefix(word string, ch byte) string {
	idx := -1
	var t byte
	bytes := []byte(word)

	for i := 0; i < len(bytes); i++ {
		if bytes[i] == ch {
			idx = i
			break
		}
	}

	if idx == -1 {
		return word
	}

	for i := 0; i <= idx/2; i++ {
		t = bytes[i]
		bytes[i] = bytes[idx-i]
		bytes[idx-i] = t
	}

	return string(bytes)
}