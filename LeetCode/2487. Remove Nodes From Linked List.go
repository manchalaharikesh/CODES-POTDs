// DATE: 06-MAY-2024
// Question URL: https://leetcode.com/problems/remove-nodes-from-linked-list/description/

// Question: 2487. Remove Nodes From Linked List
// Description: You are given the head of a linked list.

//				Remove every node which has a node with a greater value anywhere to the right side of it.

//				Return the head of the modified linked list.

// Approach: 1. The requirement is that we get a decreasing linked list of elements. Thus this approach aims at reversing the list and then constructing the increasing list then again reversing it to return the ans list.

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

func removeNodes(head *ListNode) *ListNode {
	head = reverse(head)

	temp, tail := head.Next, head

	for temp != nil {
		if temp.Val >= tail.Val {
			tail.Next = temp
			tail = temp
		}

		temp = temp.Next
	}

	tail.Next = nil
	head = reverse(head)

	return head
}