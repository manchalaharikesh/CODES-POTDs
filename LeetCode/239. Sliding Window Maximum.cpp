// DATE: 17-AUG-2023
// Question URL: https://leetcode.com/problems/01-matrix/

// Question: 239. Sliding Window Maximum
// Description: For a given array of size 'N' and window size 'K' find the maximum element in each possible window over the array.
// Approach: 1. Store elements into the heap as a pair of <nums[i], i>.
//           2. For every window assure that the top element is with in the current window range or else pop the top element.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            if(i < k-1){
                pq.push(pair<int, int>(nums[i], i));
            }
            else{
                pq.push(pair<int, int>(nums[i], i));
                pair<int, int> p = pq.top();
                while(p.second < i-k+1){
                    pq.pop();
                    p = pq.top();
                }
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};