// DATE: 23-MAR-2024
// Question URL: https://leetcode.com/problems/reorder-list/description/

// Question: 143. Reorder List
// Description: You are given the head of a singly linked-list. The list can be represented as:

//				L0 → L1 → … → Ln - 1 → Ln
//				Reorder the list to be on the following form:

//				L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//				You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Approach: 1. Code is Self-Explanatory.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		print(head)
	} else {
		var mid *ListNode = findMid(head)
		var sh *ListNode = mid.Next

		mid.Next = nil

		var rsh *ListNode = rev(sh)

		alternateJoin(head, rsh)

		print(head)
	}
}

func rev(head *ListNode) *ListNode {

	var t1, t2, temp *ListNode = head, head.Next, nil
	t1.Next = nil

	for t2 != nil {
		temp = t2.Next
		t2.Next = t1
		t1 = t2
		t2 = temp
	}

	return t1

}

func findMid(head *ListNode) *ListNode {

	var slow, fast *ListNode = head, head

	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	return slow

}

func alternateJoin(h *ListNode, rsh *ListNode) {
	var temp *ListNode

	for rsh != nil {
		temp = rsh.Next
		rsh.Next = h.Next
		h.Next = rsh
		rsh = temp
		h = h.Next.Next
	}
}

func print(head *ListNode) {
	for head != nil {
		fmt.Print(head.Val)
		head = head.Next
	}
}