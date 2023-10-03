// DATE: 03-OCT-2023
// Question URL: https://leetcode.com/problems/number-of-good-pairs/

// Question: 1512. Number of Good Pairs
// Description: Given an array arr of integers find the number of good pairs where a good pair is nums[i] == nums[j] and i < j.
// Approach: 1. Have a freq counter of elements of array and count number of pairs for freq > 1.

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> hm;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            if(hm.find(nums[i]) == hm.end()){
                hm[nums[i]] = 1;
            }
            else{
                hm[nums[i]]++;
            }
        }

        for(auto i = hm.begin(); i != hm.end(); i++){
            int c = i->second;
            if(c > 1) ans = ans + c*(c-1)/2;
        }

        return ans;
    }
};