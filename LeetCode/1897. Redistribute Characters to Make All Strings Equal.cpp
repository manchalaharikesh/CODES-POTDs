// DATE: 30-DEC-2023
// Question URL: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/

// Question: 1897. Redistribute Characters to Make All Strings Equal
// Description: You are given an array of strings words (0-indexed).

//              In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

//              Return true if you can make every string in words equal using any number of operations, and false otherwise.
// Approach: 1. Store the frequency of each character into a map then check if characters can be distributed equally into each word.

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char, int> m;
        int n = words.size();

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                if(m.find(words[i][j]) == m.end()){
                    m[words[i][j]] = 1;
                }
                else{
                    m[words[i][j]]++;
                }
            }
        }

        for(auto i: m){
            if(i.second % n != 0) return false;
        }

        return true;
    }
};