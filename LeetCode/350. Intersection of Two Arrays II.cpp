// DATE: 02-JUL-2024
// Question URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

// Question: 350. Intersection of Two Arrays II
// Description: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// Approach: 1. As to find the intersection of two arrays, we initially store elements of 1st array with their freq into a map.
//              Then we iterate elements in 2nd array, for every element we find in map and has freq > 0 we include it in our ans array and decresase the freq by 1.
//              This way when we have any val k more times in 2nd array compared to 1st array as the freq will reach 0 at some point extra elements will never be put into the ans array.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++){
            m[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); i++){
            if(m.find(nums2[i]) != m.end() && m[nums2[i]] > 0){
                m[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};