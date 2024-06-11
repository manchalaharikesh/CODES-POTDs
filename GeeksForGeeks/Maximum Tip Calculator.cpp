// DATE: 11-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1
// Question: Maximum Tip Calculator
// Description: In a restaurant, two waiters, A and B, receive n orders per day, earning tips as per arrays arr[i] and brr[i] respectively. If A takes the ith order, the tip is arr[i] rupees; if B takes it, the tip is brr[i] rupees.
//              To maximize total tips, they must distribute the orders such that:
//              A can handle at most x orders
//              B can handle at most y orders
//              Given that x + y ≥ n, all orders can be managed by either A or B. Return the maximum possible total tip after processing all the orders.
// Approach: 1. Here we need to maximize the overall tip so we sort take a vector diff, which stores the pair of {abs(arr[i]-brr[i]), i} and sort diff in descending order based on absolute diff.
//              Now we can iterate over diff and make decision on who picking the ith order.
//              The conditions for who picks the ith order and when are Self-Explanatory in the Code.
//              But remember one thing, as we are sorting the things based on the absolute difference between tips, when we get the difference between tips as 0 that means we have a tie.
//              i.e., anyone can be choosen but remember as current diff is 0 and diff is sorted further all differences are also 0 if they exist, thus we can pick anyone randomly that makes no impact (for better understanding dry run any sample test cases).

bool compare(pair<int, int> p, pair<int, int> q){
    return p.first > q.first;
}

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        vector<pair<int, int>> diff;
        int idx;
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            diff.push_back({abs(arr[i]-brr[i]), i});
        }
        
        sort(diff.begin(), diff.end(), compare);
        
        for(int i = 0; i < n; i++){
            idx = diff[i].second;
            
            if((arr[idx] >= brr[idx] && x > 0) || y == 0){
                ans += arr[idx];
                x--;
            }
            else if((arr[idx] < brr[idx] && y > 0) || x == 0){
                ans += brr[idx];
                y--;
            }
        }
        
        return ans;
    }
};