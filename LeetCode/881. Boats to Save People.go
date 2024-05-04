// DATE: 04-MAY-2024
// Question URL: https://leetcode.com/problems/boats-to-save-people/description/

// Question: 881. Boats to Save People
// Description: You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

//				Return the minimum number of boats to carry every given person.

// Approach: 1. Sort the people slice. Then we have a two pointer approach p1 = 0, p2 = len(people)-1. Then we look for accomodating persons at p1, p2 into same boat if its not possible that means we can't accomodate p2 with anyother in the slice. If its possible we can accomodate them. Further Code is Self-Explanatory.

func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	p1, p2, ans := 0, len(people)-1, 0

	for p1 <= p2 {
		if people[p1]+people[p2] <= limit {
			ans++
			p1++
			p2--
		} else {
			ans++
			p2--
		}
	}

	return ans
}