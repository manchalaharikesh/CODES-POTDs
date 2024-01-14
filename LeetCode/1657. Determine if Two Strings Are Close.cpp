// DATE: 14-JAN-2024
// Question URL: https://leetcode.com/problems/determine-if-two-strings-are-close/description/

// Question: 1657. Determine if Two Strings Are Close
// Description: Two strings are considered close if you can attain one from the other using the following operations:

//              Operation 1: Swap any two existing characters.
//              For example, abcde -> aecdb
//              Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
//              For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
//              You can use the operations on either string as many times as necessary.

//              Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
// Approach: 1. Here the strings are close if both have same unique characters and the count of unique freqs to be same irrespective of char.

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int chars1[26] = {0}, chars2[26] = {0}, m = word1.length(), n = word2.length();
        unordered_map<int, int> freq;

        if(m == n){
            for(int i = 0; i < n; i++){
                chars1[word1[i]-'a']++;
                chars2[word2[i]-'a']++;              
            }

            for(int i = 0; i < 26; i++){
                if((chars1[i] > 0) ^ (chars2[i] > 0)) return false;
                else{
                    if(freq.find(chars1[i]) == freq.end()) freq[chars1[i]] = 1;
                    else freq[chars1[i]]++;

                    if(freq.find(chars2[i]) == freq.end()) freq[chars2[i]] = -1;
                    else freq[chars2[i]]--;
                }
            }

            for(auto i: freq){
                if(i.second != 0) return false;
            }

            return true;
        }

        return false;
    }
};