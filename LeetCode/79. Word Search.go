// DATE: 03-APR-2024
// Question URL: https://leetcode.com/problems/word-search/description/

// Question: 79. Word Search
// Description: Given an m x n grid of characters board and a string word, return true if word exists in the grid.

//				The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// Approach: 1. Brute Force Code is Self-Explanatory.

func isPresent(i int, j int, pos int, board [][]byte, word string) bool {
	if pos == len(word) {
		return true
	}

	if i > 0 && board[i-1][j] == word[pos] {
		board[i-1][j] = '*'
		if isPresent(i-1, j, pos+1, board, word) {
			return true
		}
		board[i-1][j] = word[pos]
	}
	if j+1 < len(board[0]) && board[i][j+1] == word[pos] {
		board[i][j+1] = '*'
		if isPresent(i, j+1, pos+1, board, word) {
			return true
		}
		board[i][j+1] = word[pos]
	}
	if i+1 < len(board) && board[i+1][j] == word[pos] {
		board[i+1][j] = '*'
		if isPresent(i+1, j, pos+1, board, word) {
			return true
		}
		board[i+1][j] = word[pos]
	}
	if j > 0 && board[i][j-1] == word[pos] {
		board[i][j-1] = '*'
		if isPresent(i, j-1, pos+1, board, word) {
			return true
		}
		board[i][j-1] = word[pos]
	}

	return false
}

func exist(board [][]byte, word string) bool {

	for i := range board {
		for j := range board[i] {
			if board[i][j] == word[0] {
				board[i][j] = '*'
				if isPresent(i, j, 1, board, word) {
					return true
				}
				board[i][j] = word[0]
			}
		}
	}

	return false
}