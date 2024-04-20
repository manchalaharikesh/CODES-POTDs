// DATE: 20-APR-2024
// Question URL: https://leetcode.com/problems/find-all-groups-of-farmland/description/

// Question: 1992. Find All Groups of Farmland
// Description: You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

//				To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

//				land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

//				Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.
// Approach: 1. As it is guaranteed that the groups are rectangular, for every land[i][j] == 1. Find coordinates of its boundary.

func dfs(land [][]int, i, j int) []int {
	r, c := 0, 0
	temp_i, temp_j := i, j

	for i < len(land) && land[i][j] == 1 {
		r++
		i++
	}
	i = temp_i
	for j < len(land[0]) && land[i][j] == 1 {
		c++
		j++
	}

	i, j = temp_i, temp_j
	temp_i, temp_j = 0, 0

	for temp_i < r {
		temp_j = 0
		for temp_j < c {
			land[i+temp_i][j+temp_j] = 0
			temp_j++
		}
		temp_i++
	}

	return []int{i + r - 1, j + c - 1}
}

func findFarmland(land [][]int) [][]int {
	ans := make([][]int, 0, 0)
	var l []int

	for i := range len(land) {
		for j := range len(land[0]) {
			if land[i][j] == 1 {
				l = dfs(land, i, j)
				ans = append(ans, []int{i, j, l[0], l[1]})
			}
		}
	}

	return ans
}