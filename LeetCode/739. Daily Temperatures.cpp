// DATE: 31-JAN-2024
// Question URL: https://leetcode.com/problems/daily-temperatures/description/

// Question: 739. Daily Temperatures
// Description: Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
// Approach: 1. Code is Self-Explanatory.

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> ans(n, 0);

        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n;){
                if(temperatures[i] < temperatures[j]){
                    ans[i] = j-i;
                    break;
                }
                else if(ans[j] == 0){
                    ans[i] = 0;
                    break;
                }
                else{
                    j = j + ans[j];
                }
            }
        }

        return ans;
    }
};