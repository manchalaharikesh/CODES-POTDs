// DATE: 12-MAR-2024
// Question URL: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

// Question: 1171. Remove Zero Sum Consecutive Nodes from Linked List
// Description: Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
//				After doing so, return the head of the final linked list.  You may return any such answer.
//				(Note that in the examples below, all sequences are serializations of ListNode objects.)
// Approach: 1. Code is Self-Explanatory.

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeZeroSumSublists(head *ListNode) *ListNode {
	var arr []*ListNode
	m := make(map[int]*ListNode)
	temp, sum := head, 0
	var p1, p2 *ListNode

	for temp != nil {
		arr = append(arr, temp)
		temp = temp.Next
	}

	unselect := make(map[*ListNode]bool)

	for _, node := range arr {
		unselect[node] = false
	}

	for _, node := range arr {
		sum += node.Val

		if sum == 0 {
			p1 = head
			p2 = node.Next

			for p1 != p2 {
				unselect[p1] = true
				p1 = p1.Next
			}
		} else {
			_, ok := m[sum]
			if ok && !unselect[m[sum]] {
				p1 = m[sum].Next
				p2 = node.Next

				for p1 != p2 {
					fmt.Print(p1.Val)
					unselect[p1] = true
					p1 = p1.Next
				}
				fmt.Print("\n")
			} else {
				m[sum] = node
			}
		}
	}

	p1 = nil
	head = nil
	for _, node := range arr {
		if !unselect[node] {
			if p1 == nil {
				head = node
				p1 = node
			} else {
				p1.Next = node
				p1 = node
			}
			node.Next = nil
		}
	}

	return head
}