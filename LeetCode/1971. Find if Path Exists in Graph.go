// DATE: 21-APR-2024
// Question URL: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

// Question: 1971. Find if Path Exists in Graph
// Description: There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

//				You want to determine if there is a valid path that exists from vertex source to vertex destination.

//				Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
// Approach: 1. Brute Force Code is Self-Explanatory.

func dfs(m [][]int, s, d int, vis []bool) bool {
	if s == d {
		return true
	}

	for _, v := range m[s] {
		fmt.Print(v)
		if !vis[v] {
			vis[v] = true
			if dfs(m, v, d, vis) {
				return true
			}
		}
	}

	return false
}

func validPath(n int, edges [][]int, source int, destination int) bool {
	m := make([][]int, n)
	vis := make([]bool, n)

	for i := range edges {
		m[edges[i][0]] = append(m[edges[i][0]], edges[i][1])
		m[edges[i][1]] = append(m[edges[i][1]], edges[i][0])
	}

	vis[source] = true
	return dfs(m, source, destination, vis)
}