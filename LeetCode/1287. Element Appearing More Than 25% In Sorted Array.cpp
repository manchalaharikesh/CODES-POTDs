// DATE: 11-DEC-2023
// Question URL: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

// Question: 1287. Element Appearing More Than 25% In Sorted Array
// Description: Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.
// Approach: 1. Store frequency of elements in a map and iterate over it for answer.

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> m;
        int thresh = arr.size()/4, ans = -1;

        for(int i: arr){
            if(m.find(i) == m.end()) m[i] = 1;
            else m[i]++;
        }

        for(auto i: m){
            if(i.second > thresh){
                ans = i.first;
            }
        }

        return ans;
    }
};