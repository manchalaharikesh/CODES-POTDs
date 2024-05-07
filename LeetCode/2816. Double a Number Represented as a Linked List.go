// DATE: 07-MAY-2024
// Question URL: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

// Question: 2816. Double a Number Represented as a Linked List
// Description: You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

//				Return the head of the linked list after doubling it.
// Approach: 1. Reverse the list so that you can traverse from units place. Now implement the logic to multiply the number digit by digit (Code is Self-Explanatory). Then again reverse the list before returning it.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverse(head *ListNode) *ListNode {
	var temp, prev *ListNode = nil, nil

	for head != nil {
		temp = head.Next
		head.Next = prev
		prev = head
		head = temp
	}

	return prev
}

func doubleIt(head *ListNode) *ListNode {
	head = reverse(head)

	val, c := 0, 0
	var temp, tail *ListNode = head, nil

	for temp != nil {
		val = (c + temp.Val*2)
		temp.Val = val % 10
		c = val / 10
		tail = temp
		temp = temp.Next
	}

	if c != 0 {
		tail.Next = &ListNode{
			Val:  c,
			Next: nil,
		}
	}

	head = reverse(head)

	return head
}