// DATE: 19-SEP-2023
// Question URL: https://leetcode.com/problems/find-the-duplicate-number/

// Question: 287. Find the Duplicate Number
// Description: Given an array of N+1 size which has numbers only from 1 to N. There is a number present more than once. Find the number in linear time and constant space. Don't modify the array.
// Approach: 1. For a num[i] make the num[num[i]] to -ve in array. If ever found num[num[i]] is -ve return num[i].

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i < 32; i++){
            int c = 0;
            for(int j = 0; j < nums.size(); j++){
                if((nums[j] & (1 << i))) c++;
            }

            if(c > 1) ans ^= (1 << i);
        }

        return ans;
    }
};