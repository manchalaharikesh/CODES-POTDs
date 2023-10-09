// DATE: 09-OCT-2023
// Question URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Question: 34. Find First and Last Position of Element in Sorted Array
// Description: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//              If target is not found in the array, return [-1, -1].
//              You must write an algorithm with O(log n) runtime complexity.
// Approach: 1. Use Binary Serach to find first and last occurence.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int p1 = -1, p2 = -1, n = nums.size();
        vector<int> ans;
	    solve(nums, target, 0, n-1, p1, p2);
        
        ans.push_back(p1);
        ans.push_back(p2);

 	    return ans; 
    }

    void solve(vector<int>& nums, int x, int low, int high, int& p1, int& p2){
	    if(low > high) return;
	    
	    int mid = low + (high - low)/2;
	    if(nums[mid] == x){
	        if(p1 == -1){
	            p1 = mid;
	            p2 = mid;
                solve(nums, x, low, mid-1, p1, p2);
                solve(nums, x, mid+1, high, p1, p2);
	        }
	        else if(mid < p1){
	            p1 = mid;
	            solve(nums, x, low, mid-1, p1, p2);
	        }
	        else if(mid > p2){
	            p2 = mid;
	            solve(nums, x, mid+1, high, p1, p2);
	        }
	    }
	    else if(nums[mid] < x){
	        solve(nums, x, mid+1, high, p1, p2);
	    }
	    else{
	        solve(nums, x, low, mid-1, p1, p2);
	    }
	}
};