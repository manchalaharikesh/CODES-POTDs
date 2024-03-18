// DATE: 18-MAR-2024
// Question URL: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

// Question: 452. Minimum Number of Arrows to Burst Balloons
// Description: There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

//				Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

//				Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
// Approach: 1. Sort the points based on both start and end. And at each iteration mark minimum end encountered. If anytime point has start greater than minimum end stored that means previous arrow cannot hit it. So increment counter and update minimum end to new instance.

import "sort"

func findMinArrowShots(points [][]int) int {
	sort.Slice(points, func(i int, j int) bool {
		if points[i][0] == points[j][0] {
			return points[i][1] < points[j][1]
		}
		return points[i][0] < points[j][0]
	})
	ans, p1, thresh := 1, 1, points[0][1]

	for p1 < len(points) {
		if points[p1][0] > thresh {
			thresh = points[p1][1]
			ans++
		} else {
			thresh = min(thresh, points[p1][1])
		}
		p1++
	}

	return ans
}