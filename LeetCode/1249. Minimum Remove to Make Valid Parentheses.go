// DATE: 06-APR-2024
// Question URL: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

// Question: 1249. Minimum Remove to Make Valid Parentheses
// Description: Given a string s of '(' , ')' and lowercase English characters.

//				Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

//				Formally, a parentheses string is valid if and only if:

//				It is the empty string, contains only lowercase characters, or
//				It can be written as AB (A concatenated with B), where A and B are valid strings, or
//				It can be written as (A), where A is a valid string.
// Approach: 1. Code is Self-Explanatory.

type Stack struct {
	items []int
}

func (s *Stack) Push(item int) {
	s.items = append(s.items, item)
}

func (s *Stack) Pop() int {
	if len(s.items) == 0 {
		return 0
	}
	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item
}

func (s *Stack) Peek() int {
	if len(s.items) == 0 {
		return 0
	}
	return s.items[len(s.items)-1]
}

func (s *Stack) isEmpty() bool {
	return len(s.items) == 0
}

func minRemoveToMakeValid(s string) string {
	st := Stack{}
	str := []byte(s)
	ans := ""

	for i, ch := range str {
		if ch == ')' {
			if st.isEmpty() {
				str[i] = '*'
			} else {
				st.Pop()
			}
		} else if ch == '(' {
			st.Push(i)
		}
	}

	for !st.isEmpty() {
		str[st.Peek()] = '*'
		st.Pop()
	}

	for _, ch := range str {
		if ch != '*' {
			ans = ans + string(ch)
		}
	}

	return ans
}