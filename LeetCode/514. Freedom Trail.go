// DATE: 27-APR-2024
// Question URL: https://leetcode.com/problems/freedom-trail/description/

// Question: 514. Freedom Trail
// Description: In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.

//				Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.

//				Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.

//				At the stage of rotating the ring to spell the key character key[i]:

//				You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
//				If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.
// Approach: 1. For every character of key there can be multiple possibilities in ring. So we need a 3D matrix for storing the solutions at each stage. dp[i][j][k] means ith char of key, j is from which char we are moving to current key[i] in ring and k is one of the possibilities for key[i] in ring.
//				It's not possible to explain this particular code in two lines.

import "math"

func dfs(curr, idx int, key string, m map[byte][]int, dp [][][]int, distance [][]int) int {
	if idx == len(key) {
		return 0
	}

	_min := math.MaxInt32
	for j := range m[key[idx]] {
		if dp[idx][curr][j] == math.MaxInt32 {
			dp[idx][curr][j] = distance[curr][m[key[idx]][j]] + 1 + dfs(m[key[idx]][j], idx+1, key, m, dp, distance)
		}
		_min = min(_min, dp[idx][curr][j])
	}

	return _min
}

func findRotateSteps(ring string, key string) int {
	m, dp := make(map[byte][]int), make([][][]int, len(key))
	n, c := len(ring), 0
	distance := make([][]int, n)
	ans := math.MaxInt32

	for i := range n {
		distance[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		c = 0
		for j := i + 1; c < (n-1)/2+(n-1)%2; j++ {
			distance[i][j%n] = c + 1
			c++
		}

		c = 0
		for j := i - 1; c < (n-1)/2+(n-1)%2; j-- {
			distance[i][(n+j)%n] = c + 1
			c++
		}
	}

	for i := range ring {
		if _, ok := m[ring[i]]; !ok {
			m[ring[i]] = make([]int, 0)
		}

		m[ring[i]] = append(m[ring[i]], i)
	}

	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, n)
			for k := range dp[i][j] {
				dp[i][j][k] = math.MaxInt32
			}
		}
	}

	dfs(0, 0, key, m, dp, distance)

	for k := range dp[0][0] {
		ans = min(ans, dp[0][0][k])
	}

	return ans
}