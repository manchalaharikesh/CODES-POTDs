// DATE: 05-APR-2024
// Question URL: https://leetcode.com/problems/make-the-string-great/description/

// Question: 1544. Make The String Great
// Description: Given a string s of lower and upper case English letters.

//				A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

//				0 <= i <= s.length - 2
//				s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
//				To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

//				Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

//				Notice that an empty string is also good.
// Approach: 1. Brute Force Code is Self-Explanatory.

import "unicode"

type Stack struct {
	items []rune
}

func (s *Stack) Push(item rune) {
	s.items = append(s.items, item)
}

func (s *Stack) Pop() rune {
	if len(s.items) == 0 {
		return 0
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item
}

func (s *Stack) Peek() rune {
	if len(s.items) == 0 {
		return 0
	}
	return s.items[len(s.items)-1]
}

func (s *Stack) isEmpty() bool {
	return len(s.items) == 0
}

func makeGood(s string) string {
	stack := Stack{}
	ans := ""

	for _, char := range s {
		if !stack.isEmpty() {
			if unicode.IsLower(char) && stack.Peek() == unicode.ToUpper(char) {
				stack.Pop()
			} else if unicode.IsUpper(char) && stack.Peek() == unicode.ToLower(char) {
				stack.Pop()
			} else {
				stack.Push(char)
			}
		} else {
			stack.Push(char)
		}
	}

	for !stack.isEmpty() {
		ans = string(stack.Peek()) + ans
		stack.Pop()
	}

	return ans
}