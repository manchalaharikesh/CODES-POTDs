// DATE: 19-MAR-2024
// Question URL: https://leetcode.com/problems/task-scheduler/description/

// Question: 621. Task Scheduler
// Description: You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

//				​Return the minimum number of intervals required to complete all tasks.
// Approach: 1. Code Self-Explanatory.

import "sort"

func leastInterval(tasks []byte, n int) int {
	var (
		freq   = make([]int, 26)
		l      int
		spaces int
		p1     int
	)

	for _, ch := range tasks {
		freq[ch-65]++
	}

	sort.Slice(freq, func(i, j int) bool { return freq[i] > freq[j] })

	spaces = (freq[0] - 1) * n
	l = spaces + freq[0]
	p1 = 1

	fmt.Print(freq)

	for p1 < len(freq) && freq[p1] != 0 {
		if freq[0] == freq[p1] && spaces != 0 {
			l++
			spaces = spaces - freq[p1] + 1
		} else if spaces >= freq[p1] {
			spaces -= freq[p1]
		} else {
			l = l + freq[p1] - spaces
			spaces = 0
		}

		p1++
	}

	return l
}