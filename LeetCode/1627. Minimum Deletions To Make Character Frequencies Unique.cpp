// DATE: 12-SEP-2023
// Question URL: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

// Question: 1627. Minimum Deletions To Make Character Frequencies Unique
// Description: Given a string of smaller alphabets, find the minimum cost to make the string to have character frequencies to be unique. 
//              Consider cost for each deletion be 1 and you might also delete a char completely.
// Approach: 1. Store the frequencies of each character in the array.
//           2. Create a hashmap to store values like (freq, char).
//           3. Decrease the freq of a char until the freq is not in hashmap.
// TC: O(2*N) ~ O(N)

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        map<int, int> hm;
        int cost = 0;

        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                if(hm.find(freq[i]) == hm.end()){
                    hm[freq[i]] = 65+i;
                    break;
                }
                cost++;
                freq[i]--;
            }
        }

        return cost;
    }
};