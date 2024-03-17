// DATE: 17-MAR-2024
// Question URL: https://leetcode.com/problems/insert-interval/description/

// Question: 57. Insert Interval
// Description: You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

//				Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

//				Return intervals after the insertion.

//				Note that you don't need to modify intervals in-place. You can make a new array and return it.
// Approach: 1. Code is Self-Explanatory.

func insert(intervals [][]int, newInterval []int) [][]int {
	ans := make([][]int, 0, len(intervals)+1)
	spos, rpos, soverlap, roverlap := -1, -1, false, false

	// base conditions
	if len(intervals) == 0 {
		ans = append(ans, newInterval)
		return ans
	} else if newInterval[1] < intervals[0][0] {
		ans = append(ans, newInterval)
		for _, interval := range intervals {
			ans = append(ans, interval)
		}
		return ans
	} else if intervals[len(intervals)-1][1] < newInterval[0] {
		intervals = append(intervals, newInterval)
		return intervals
	}

	// find start position
	for idx, interval := range intervals {
		if interval[0] <= newInterval[0] && newInterval[0] <= interval[1] {
			spos = idx
			soverlap = true
			break
		} else if interval[0] > newInterval[0] {
			spos = idx - 1
			break
		}
	}

	// find end position
	for idx, interval := range intervals {
		if interval[0] <= newInterval[1] && newInterval[1] <= interval[1] {
			rpos = idx
			roverlap = true
			break
		} else if interval[0] > newInterval[1] {
			rpos = idx
			break
		}
	}

	// if newInterval[1] > intervals[len(intervals)-1][1]
	if rpos == -1 {
		rpos = len(intervals)
	}

	for _, interval := range intervals[:spos+1] {
		ans = append(ans, interval)
	}

	if !soverlap && !roverlap {
		ans = append(ans, newInterval)
		for _, interval := range intervals[rpos:] {
			ans = append(ans, interval)
		}
	} else if soverlap && !roverlap {
		for _, interval := range intervals[rpos:] {
			ans = append(ans, interval)
		}
		ans[spos][1] = newInterval[1]
	} else if !soverlap && roverlap {
		intervals[rpos][0] = newInterval[0]
		for _, interval := range intervals[rpos:] {
			ans = append(ans, interval)
		}
	} else {
		ans[spos][1] = intervals[rpos][1]
		for _, interval := range intervals[rpos+1:] {
			ans = append(ans, interval)
		}
	}

	return ans
}