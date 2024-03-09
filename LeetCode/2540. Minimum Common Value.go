// DATE: 09-MAR-2024
// Question URL: https://leetcode.com/problems/minimum-common-value/description/

// Question: 2540. Minimum Common Value
// Description: Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

//				Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

// Approach: 1. Code is Self Explanatory.

func getCommon(nums1 []int, nums2 []int) int {
    var i, j int = 0, 0
    var n1, n2 int = len(nums1), len(nums2)

    for i < n1 && j < n2 {
        if nums1[i] == nums2[j] {
            return nums1[i]
        }

        if nums1[i] < nums2[j] {
            i++
        } else {
            j++
        }
    }

    return -1
}