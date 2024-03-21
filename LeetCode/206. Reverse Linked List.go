// DATE: 21-MAR-2024
// Question URL: https://leetcode.com/problems/reverse-linked-list/description/

// Question: 206. Reverse Linked List
// Description: Given the head of a singly linked list, reverse the list, and return the reversed list.
// Approach: 1. Code is Self-Explanatory.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	var prev, temp *ListNode = nil, nil

	for head != nil {
		temp = head.Next
		head.Next = prev
		prev = head
		head = temp
	}

	return prev
}