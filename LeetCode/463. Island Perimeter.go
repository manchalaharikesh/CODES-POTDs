// DATE: 18-APR-2024
// Question URL: https://leetcode.com/problems/island-perimeter/description/

// Question: 463. Island Perimeter
// Description: You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

//				Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

//				The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
// Approach: 1. Code is Self-Explanatory.

func islandPerimeter(grid [][]int) int {
	ans := 0
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 1 {
				if i-1 < 0 || (i-1 >= 0 && grid[i-1][j] == 0) {
					ans++
				}
				if j-1 < 0 || (j-1 >= 0 && grid[i][j-1] == 0) {
					ans++
				}
				if i+1 == len(grid) || (i+1 < len(grid) && grid[i+1][j] == 0) {
					ans++
				}
				if j+1 == len(grid[0]) || (j+1 < len(grid[0]) && grid[i][j+1] == 0) {
					ans++
				}
			}
		}
	}

	return ans
}