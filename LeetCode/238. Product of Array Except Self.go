// DATE: 15-MAR-2024
// Question URL: https://leetcode.com/problems/product-of-array-except-self/description/

// Question: 238. Product of Array Except Self
// Description: Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

//				The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

//				You must write an algorithm that runs in O(n) time and without using the division operation.

// Approach: 1. Have prefix and suffix products.

func productExceptSelf(nums []int) []int {
	muls := make([]int, len(nums))
	right := 1

	muls[0] = 1

	// left muls
	for i := 1; i < len(muls); i++ {
		muls[i] = muls[i-1] * nums[i-1]
	}

	// right muls
	for i := len(muls) - 2; i >= 0; i-- {
		right = right * nums[i+1]
		muls[i] = muls[i] * right
	}

	return muls
}