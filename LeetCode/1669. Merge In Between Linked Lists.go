// DATE: 20-MAR-2024
// Question URL: https://leetcode.com/problems/merge-in-between-linked-lists/description/

// Question: 1669. Merge In Between Linked Lists
// Description: You are given two linked lists: list1 and list2 of sizes n and m respectively.

//				Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

//				The blue edges and nodes in the following figure indicate the result:

//				https://assets.leetcode.com/uploads/2020/11/05/fig1.png

//				Build the result list and return its head.
// Approach: 1. Brute Force or Code is Self-Explanatory.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
	var p1, p2, temp, list2_tail *ListNode = list1, list1, list1.Next, nil

	for a > 1 || b > 0 {
		if a > 1 {
			p1 = temp
		}
		p2 = temp
		temp = temp.Next
		a--
		b--
	}

	temp = list2
	for temp != nil {
		list2_tail = temp
		temp = temp.Next
	}

	list2_tail.Next = p2.Next
	p1.Next = list2

	return list1
}