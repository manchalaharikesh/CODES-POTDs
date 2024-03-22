// DATE: 22-MAR-2024
// Question URL: https://leetcode.com/problems/palindrome-linked-list/description/

// Question: 234. Palindrome Linked List
// Description: Given the head of a singly linked list, return true if it is a
//				palindrome or false otherwise.

// Approach: 1. Reverse second half of the list. And check with two pointer traversal whether it is a palindrome or not.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}

	var slow, fast, p1, p2, mid_node *ListNode = head, head.Next, nil, nil, nil

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	slow.Next = reverse(slow.Next)
	p1 = head
	p2 = slow.Next

	if fast == nil {
		mid_node = slow
	} else {
		mid_node = slow.Next
	}

	for p1 != mid_node {
		if p1.Val != p2.Val {
			return false
		}

		p1 = p1.Next
		p2 = p2.Next
	}

	return true
}

func reverse(head *ListNode) *ListNode {
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