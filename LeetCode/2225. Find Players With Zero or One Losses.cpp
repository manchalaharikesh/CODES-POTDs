// DATE: 15-JAN-2024
// Question URL: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

// Question: 2225. Find Players With Zero or One Losses
// Description: You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

//              Return a list answer of size 2 where:

//              answer[0] is a list of all players that have not lost any matches.
//              answer[1] is a list of all players that have lost exactly one match.
//              The values in the two lists should be returned in increasing order.

//              Note:

//              You should only consider the players that have played at least one match.
//              The testcases will be generated such that no two matches will have the same outcome.
// Approach: 1. Hashmap to store freqs of winners and losers.

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> winners, losers;
        vector<vector<int>> res(2, vector<int>());

        for(int i = 0; i < matches.size(); i++){
            if(winners.find(matches[i][0]) == winners.end()) winners[matches[i][0]] = 1;
            else winners[matches[i][0]]++;

            if(losers.find(matches[i][1]) == losers.end()) losers[matches[i][1]] = 1;
            else losers[matches[i][1]]++;
        }

        for(auto it: winners){
            if(losers.find(it.first) == losers.end()) res[0].push_back(it.first);
        }

        for(auto it: losers){
            if(it.second == 1) res[1].push_back(it.first);
        }

        // sort(res[0].begin(), res[0].end());
        // sort(res[1].begin(), res[1].end());

        return res;
    }
};