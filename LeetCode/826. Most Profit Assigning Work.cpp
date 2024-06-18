// DATE: 18-JUN-2024
// Question URL: https://leetcode.com/problems/most-profit-assigning-work/

// Question: 826. Most Profit Assigning Work
// Description: You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

//              difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
//              worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
//              Every worker can be assigned at most one job, but one job can be completed multiple times.

//              For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
//              Return the maximum profit we can achieve after assigning the workers to the jobs.
// Approach: 1. In this approach we focus on sorting the difficulty and profits in decreasing order whose custom sort depends on profit initially, if profits are equal the sort is based higher difficulty.
//              The motive behind sorting difficulty and profits based on decreasing order of profit is to leverage the benefit of each capable individual allowed to do same work multiple times and get higher profits (regardless of whether he can handle other job with high difficulty which eventually has less profit).
//              The worker array is also sorted in decreasing order, this way we ensured that every worker gets work with higher profit among all the works that are under his capacity of difficulty.
//              As the worker is sorted in descending order we can ensure that the current high paying work is only skipped if current worker can't do it which means no one can do it after him (as sorted in decreasing order).

bool compare(pair<int, int> p, pair<int, int>  q){
    if(p.second == q.second) return p.first > q.first;
    return p.second > q.second;
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> arr;
        int p = 0, ans = 0;

        for(int i = 0; i < difficulty.size(); i++){
            arr.push_back({difficulty[i], profit[i]});
        }

        sort(arr.begin(), arr.end(), compare);
        sort(worker.begin(), worker.end(), greater<int>());

        for(int i = 0; i < worker.size(); i++){
            while(p < arr.size() && arr[p].first > worker[i]) p++;
            if(p == arr.size()) break;
            ans += arr[p].second;
        }

        return ans;
    }
};