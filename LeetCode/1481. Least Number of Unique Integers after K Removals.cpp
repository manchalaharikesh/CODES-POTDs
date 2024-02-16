// DATE: 16-FEB-2024
// Question URL: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

// Question: 1481. Least Number of Unique Integers after K Removals
// Description: Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
// Approach: 1. Code is Self-Explanatory.

class Compare{
    public:
    bool operator()(pair<int, int> p, pair<int, int> q){
        return p.second < q.second;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> m;
        vector<pair<int, int>> v;
        int ans = 0;

        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }

        for(auto it: m){
            v.push_back({it.first, it.second});
        }

        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << "\n";

        sort(v.begin(), v.end(), Compare());

        ans = v.size();
        for(int i = 0; k != 0; i++){
            if(v[i].second <= k){
                k -= v[i].second;
                v[i].second = 0;
                ans--;
            }
            else if(v[i].second > k){
                v[i].second -= k;
                k = 0;
            }
        }

        return ans;
    }
};