// DATE: 17-JAN-2024
// Question URL: https://leetcode.com/problems/unique-number-of-occurrences/description/

// Question: 1207. Unique Number of Occurrences
// Description: Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
// Approach: 1. Store freqs in a map then store the freq in set if any time the same freq exists return false if reached end return true.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> t;

        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }

        for(auto it: m){
            if(t.find(it.second) == t.end()) t.insert(it.second);
            else return false;
        }

        return true;
    }
};