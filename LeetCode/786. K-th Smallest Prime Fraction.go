// DATE: 10-MAY-2024
// Question URL: https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

// Question: 786. K-th Smallest Prime Fraction
// Description: You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

//				For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

//				Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
// Approach: 1. Find all the fractions in an n^2 approach. Simultaneously store element indices i, j along with fraction. Now sort the fractions based on fraction in non-decreasing fashion and return elements corresponding to kth smallest fraction.

import "sort"

type MySlice [][]float64

func (s MySlice) Len() int {
	return len(s)
}

func (m MySlice) Less(i, j int) bool {
	return m[i][0] < m[j][0]
}

func (m MySlice) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func kthSmallestPrimeFraction(arr []int, k int) []int {
	var temp MySlice

	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			l := []float64{float64(arr[i]) / float64(arr[j]), float64(i), float64(j)}
			temp = append(temp, l)
		}
	}

	sort.Sort(temp)

	// fmt.Println(temp)

	return []int{arr[int(temp[k-1][1])], arr[int(temp[k-1][2])]}
}