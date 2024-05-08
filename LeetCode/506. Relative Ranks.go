// DATE: 08-MAY-2024
// Question URL: https://leetcode.com/problems/relative-ranks/description/

// Question: 506. Relative Ranks
// Description: You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

//				The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

//				The 1st place athlete's rank is "Gold Medal".
//				The 2nd place athlete's rank is "Silver Medal".
//				The 3rd place athlete's rank is "Bronze Medal".
//				For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
//				Return an array answer of size n where answer[i] is the rank of the ith athlete.
// Approach: 1. Copy the scores into a temp. Sort the temp and have their ranks in a map. Now for every element in score get rank from map and update ans []string array with string ranks.

import (
	"sort"
	"strconv"
)

func findRelativeRanks(score []int) []string {
	temp := make([]int, len(score))
	m := make(map[int]int)
	ans := make([]string, len(score))

	copy(temp, score)
	sort.Ints(temp)

	for i := range temp {
		m[temp[i]] = len(temp) - i
	}

	for i := range score {
		if m[score[i]] <= 3 {
			if m[score[i]] == 1 {
				ans[i] = "Gold Medal"
			} else if m[score[i]] == 2 {
				ans[i] = "Silver Medal"
			} else if m[score[i]] == 3 {
				ans[i] = "Bronze Medal"
			}
		} else {
			ans[i] = strconv.Itoa(m[score[i]])
		}
	}

	return ans
}