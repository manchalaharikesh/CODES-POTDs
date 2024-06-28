// DATE: 28-JUN-2024
// Question URL: https://leetcode.com/problems/maximum-total-importance-of-roads/description/

// Question: 2285. Maximum Total Importance of Roads
// Description: You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

//              You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

//              You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

//              Return the maximum total importance of all roads possible after assigning the values optimally.
// Approach: 1. Here we need to assign an importance to each city. Then the importance of each road becomes the sum of the importance of those two cities it connects.
//              We need to optimally find the largest sum of importance of roads that is possible.
//              So to get maximum importance, it is clear that the city with highest degree must be given highest importance by which the maximum possible value is considered maximum number of times (degree of times).
//              Now let us say we have the cities and its frequencies in a vector, now we sort this vector in ascending order of cities degree or connectivity.
//              Then we have importance of i+1 assigned to city at ith index and its freq or connectivity is given by freqs[i].
//              Then we have this importance (i+1) included for freq[i] times in calculating the answer, so we simply have freq[i]*(i+1) as the contribution of ith city to the total maximum importance possible (refer to example-1 of this question on leetcode for better understanding).

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freqs(n, 0);
        long long ans = 0;

        for(int i = 0; i < roads.size(); i++){
            freqs[roads[i][0]]++;
            freqs[roads[i][1]]++;
        }

        sort(freqs.begin(), freqs.end());

        for(long i = 0; i < n; i++){
            ans = ans + freqs[i]*(i+1);
        }

        return ans;
    }
};