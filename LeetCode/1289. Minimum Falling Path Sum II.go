// DATE: 26-APR-2024
// Question URL: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

// Question: 1289. Minimum Falling Path Sum II
// Description: Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

//	A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.
//
// Approach: 1. At dp[i][j] store the minimum sum possible with falling path with non-zero shifts from (i, j)th point. Apply a backtracking algorithm and continue if and only if dp[i][j] doesn't have a solution marked.
//				Simply we solve matrix grid completely by solving grid[n-1:n], grid[n-2:n], grid[n-3:n], ..., grid[0:n].
//				The brute force solution is a backtracking algorithm. Thus to prevent exploring positions reptitively we store the solution at that point in dp matrix.

func solve(i, j, v, n int, grid, dp [][]int) int {
	_min := math.MaxInt32
	for j < n {
		if j != v {
			if dp[i][j] == math.MaxInt32 {
				dp[i][j] = grid[i][j] + solve(i+1, 0, j, n, grid, dp)
				_min = min(_min, dp[i][j])
			} else {
				_min = min(_min, dp[i][j])
			}
		}
		j++
	}

	return _min
}

func minFallingPathSum(grid [][]int) int {
	n := len(grid)
	dp := make([][]int, n)

	for i := range n {
		dp[i] = make([]int, n)
		for j := range n {
			dp[i][j] = math.MaxInt32
		}
	}

	dp[n-1] = grid[n-1]

	solve(0, 0, -1, n, grid, dp)

	ans := math.MaxInt32

	for j := range n {
		ans = min(ans, dp[0][j])
	}

	return ans
}