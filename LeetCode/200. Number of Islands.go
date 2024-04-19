// DATE: 19-APR-2024
// Question URL: https://leetcode.com/problems/number-of-islands/description/

// Question: 200. Number of Islands
// Description: Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

//				An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// Approach: 1. Brute Force Code is Self-Explanatory.

func dfs(grid [][]byte, i, j int) {
	if i-1 >= 0 && grid[i-1][j] == '1' {
		grid[i-1][j] = '0'
		dfs(grid, i-1, j)
	}
	if j-1 >= 0 && grid[i][j-1] == '1' {
		grid[i][j-1] = '0'
		dfs(grid, i, j-1)
	}
	if i+1 < len(grid) && grid[i+1][j] == '1' {
		grid[i+1][j] = '0'
		dfs(grid, i+1, j)
	}
	if j+1 < len(grid[0]) && grid[i][j+1] == '1' {
		grid[i][j+1] = '0'
		dfs(grid, i, j+1)
	}
}

func numIslands(grid [][]byte) int {
	ans := 0
	for i := range len(grid) {
		for j := range len(grid[0]) {
			if grid[i][j] == '1' {
				ans++
				grid[i][j] = '0'
				dfs(grid, i, j)
			}
		}
	}

	return ans
}