// DATE: 05-JUN-2024
// Question URL: https://leetcode.com/problems/find-common-characters/description/

// Question: 1002. Find Common Characters
// Description: Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
// Approach: 1. The approach of this problem is to store the freq of all characters of each string seperately.
//              Then we look for each character whether it have occured in all the strings and pick the minimum freq of it to correctly choose the number of duplicates of that character, to be placed into ans.

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> table(words.size(), vector<int>(26, 0));
        vector<string> ans;
        int freq = 0;

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                table[i][words[i][j] - 97]++;
            }
        }

        for(int j = 0; j < 26; j++){
            freq = INT_MAX;
            for(int i = 0; i < words.size(); i++){
                freq = min(table[i][j], freq);
            }
            string s;
            s += static_cast<char>(j+97);
            for(int i = 0; i < freq; i++){
                ans.push_back(s);
            }
        }

        return ans;
    }
};