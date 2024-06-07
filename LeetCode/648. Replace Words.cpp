// DATE: 07-JUN-2024
// Question URL: https://leetcode.com/problems/replace-words/description/

// Question: 648. Replace Words
// Description: In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

//              Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

//              Return the sentence after the replacement.
// Approach: 1. Here we initially store each dictionary root word into a map.
//              Then we take each individual word of the sentence, then we iterate through this word to get substring starting with initial character and incrementally we check if this is in the map, if so this is the root word possible.
//              Then we add this new word (substring) to our new sentence.

//              e.g: dictionary / map: {cat, dog}.
//                   sentence: "cattle bottle" => c not in map, ca not in map, cat present in map so cattle root is cat.
//                                             => b not in map, bo not in map, ...., bottle not in map so consider the whole word.
//                   new sentence: "cat bottle".

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string, int> m;
        vector<int> idxs;
        string ans = "";

        for(int i = 0; i < dictionary.size(); i++){
            m[dictionary[i]]++;
        }

        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] != ' '){
                idxs.push_back(i);
                for(; i < sentence.length() && sentence[i] != ' '; i++);
            }
        }

        for(int i = 0; i < idxs.size(); i++){
            string s = "";
            bool flag = false;
            for(int j = idxs[i]; j < sentence.length() && sentence[j] != ' '; j++){
                s = s + sentence[j];
                if(m.find(s) != m.end()){ 
                    ans = ans + (idxs[i] != 0 ? ' ' + s : s);
                    flag = true;
                    break;
                }
            }
            if(!flag) ans = ans + (idxs[i] != 0 ? ' ' + s : s);
        }

        return ans;
    }
};