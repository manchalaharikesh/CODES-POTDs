// DATE: 06-FEB-2024
// Question URL: https://leetcode.com/problems/group-anagrams/description/

// Question: 49. Group Anagrams
// Description: Given an array of strings strs, group the anagrams together. You can return the answer in any order.

//              An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// Approach: 1. Store in hashmap then have a nested iteration to group anagrams.

class Solution {
public:
    bool areAnagrams(vector<vector<int>>& v, int i, int j){
        for(int k = 0; k < 26; k++){
            if(v[i][k] != v[j][k]) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> v(strs.size(), vector<int>(26, 0));
        vector<bool> flag(strs.size(), false);
        vector<vector<string>> ans;

        for(int i = 0; i < strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++){
                v[i][strs[i][j] - 'a']++;
            }
        }

        for(int i = 0; i < strs.size(); i++){
            if(flag[i]) continue;
            ans.push_back(vector<string>{strs[i]});
            flag[i] = true;
            for(int j = i+1; j < strs.size(); j++){
                if(strs[i].size() != strs[j].size()) continue;
                if(areAnagrams(v, i, j)){
                    ans[ans.size()-1].push_back(strs[j]);
                    flag[j] = true;
                }
            }
        }

        return ans;
    }
};