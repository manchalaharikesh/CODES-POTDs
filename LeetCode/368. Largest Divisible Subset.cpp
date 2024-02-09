// DATE: 09-FEB-2024
// Question URL: https://leetcode.com/problems/largest-divisible-subset/description/

// Question: 368. Largest Divisible Subset
// Description: Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

//              answer[i] % answer[j] == 0, or
//              answer[j] % answer[i] == 0
//              If there are multiple solutions, return any of them.
// Approach: 1. We sort the array. Then we have a dp array, where dp[i] is the length of the longest subset possible with given conditions from i to n. 
//              With dp array construction we also focus on storing the next element of this sequence. Then we look for a global maximum possible length in dp. 
//              Traversing it with next values gives us the required answer.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), ans;
        int _max = 0, num;
        
        sort(nums.begin(), nums.end());

        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(nums[j] % nums[i] == 0 && dp[i] <= dp[j]){
                    dp[i] = dp[j] + 1;
                }
            }
            if(_max < dp[i]){
                _max = dp[i];
                num = nums[i];
            }
        }

        for(int i = 0; i < n; i++){
            if(dp[i] == _max && (nums[i]%num == 0)){
                ans.push_back(nums[i]);
                num = nums[i];
                _max--;
            }
        }

        return ans;
    }
};