// DATE: 21-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
// Question: Stickler Thief
// Description: For a arr of loot available in each house. Find the maximum loot the thief can stole if the thief follows the rule that he doesn't rob in two consecutive houses.
// Approach: 1. Backtracking each possible way to rob and get maximum of them.
//           2. Implement a DP approach where at ith state we store the maximum loot available from ith house to nth house.
//           3. The above DP can be optimized in space. As if we observe carefully we would need a constant space as we only depend on (i+1)th and (i+2)th states to calculate ith state (as at ith state we can consider (i+2)th state or (i+1)th state alone).

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1) return arr[0];
        else if(n == 0) return 0;
     
        int dp[2] = {max(arr[n-2], arr[n-1]), arr[n-1]};
        int idx = 0;
        
        for(int i = n-3; i >= 0; i--){
            if((n-i) & 1) idx = 1;
            else idx = 0;
            
            dp[idx] = max(arr[i] + dp[idx], dp[!idx]);
        }
        
        return dp[n%2];
    }
};