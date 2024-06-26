// DATE: 03-MAY-2024
// Question URL: https://leetcode.com/problems/compare-version-numbers/description/

// Question: 165. Compare Version Numbers
// Description: Given two version numbers, version1 and version2, compare them.

//				Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

//				To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

// Approach: 1. Brute Force / Code is Self-Explanatory.

import (
	"strings"
	"strconv"
)

func compareVersion(version1 string, version2 string) int {
	var rev1, rev2 []string
	var i int

	rev1 = strings.Split(version1, ".")
	rev2 = strings.Split(version2, ".")

	for i = 0; i < min(len(rev1), len(rev2)); i++ {
		n1, _ := strconv.Atoi(rev1[i])
		n2, _ := strconv.Atoi(rev2[i])

		if n1 > n2 {
			return 1
		} else if n1 < n2 {
			return -1
		}
	}

	for ; i < len(rev1); i++ {
		n1, _ := strconv.Atoi(rev1[i])
		if n1 > 0 {
			return 1
		}
	}

	for ; i < len(rev2); i++ {
		n2, _ := strconv.Atoi(rev2[i])
		if n2 > 0 {
			return -1
		}
	}

	return 0
}