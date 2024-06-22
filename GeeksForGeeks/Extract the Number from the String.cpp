// DATE: 22-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1
// Question: Extract the Number from the String
// Description: Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

//              Note: Numbers and words are separated by spaces only.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    bool NoNine(string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '9') return false;
        }
        
        return true;
    }
    
    long long ExtractNumber(string sentence) {
        vector<string> words;
        string s = "";
        long long ans = -1;
        
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] != ' ') s += sentence[i];
            else{
                words.push_back(s);
                s = "";
            }
        }
        
        for(int i = 0; i < words.size(); i++){
            if(words[i][0] >= '0' && words[i][0] <= '9'){
                if(NoNine(words[i])) ans = max(ans, stoll(words[i]));
            }
        }
        
        return ans;
    }
};