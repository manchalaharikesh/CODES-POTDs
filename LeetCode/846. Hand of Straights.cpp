// DATE: 06-JUN-2024
// Question URL: https://leetcode.com/problems/hand-of-straights/description/

// Question: 846. Hand of Straights
// Description: Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

//              Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
// Approach: 1. In this approach we sort the vector hands. Then we store the frequency of elements into a map.
//              Now we iterate through hands and when we have choosen the first element of a group we take it if and only if its freq is available through map.
//              Then for this choosen initial element of a group we verify if there are groupSize consecutive elements available through freq in map. If not return false after checking all elements return true.
//              For better understanding refer to code / LeetCode-solutions 😂.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        
        map<int, int> m;
        int curr;
        
        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); i++){
            m[hand[i]]++;
        }

        for(int i = 0; i < hand.size(); i++){
            if(m[hand[i]] > 0){
                curr = hand[i];
                m[hand[i]]--;
                for(int j = 1; j < groupSize; j++){
                    if(m[curr+1] > 0) m[++curr]--;
                    else return false;
                }
            }
        }

        return true;
    }
};