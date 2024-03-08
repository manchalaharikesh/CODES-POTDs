// DATE: 08-MAR-2024
// Question URL: https://leetcode.com/problems/count-elements-with-maximum-frequency/submissions/

// Question: 3005. Count Elements With Maximum Frequency
// Description: You are given an array nums consisting of positive integers.

//				Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

//				The frequency of an element is the number of occurrences of that element in the array.

// Approach: 1. Store the freq of nums ina freq slice. Now while storing freqs also store max freq along with the count of its occurences. Return count * max_freq.

func maxFrequencyElements(nums []int) int {
    var _max, c int = 0, 0
    freq := make([]int, 100)
	    
    for i := 0; i < len(nums); i++{
        freq[nums[i] - 1]++
        if freq[nums[i] - 1] == _max {
            c++
        } else if freq[nums[i] - 1] > _max {
            _max = freq[nums[i] - 1]
            c = 1
        }
    }
	    
	return c * _max;
}