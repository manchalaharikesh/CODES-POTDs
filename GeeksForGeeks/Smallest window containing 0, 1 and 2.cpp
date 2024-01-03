// DATE: 03-JAN-2023
// Question URL: https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1
// Question: Smallest window containing 0, 1 and 2
// Description: Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.
// Approach: 1. Use two pointer approach where, calculate the frequency of each char available by p2. If all the freqs are available update the answer accordingly and inc p1 and also dec freq accordingly.

class Solution {
  public:
    int smallestSubstring(string S) {
        int p1 = 0, p2 = 0;
        int res = INT_MAX;
        bool flag = true;
        
        int counts[3] = {0};
        
        while(p2 < S.length()){
            if(flag) counts[S[p2] - '0']++;
            
            if(counts[0] > 0 && counts[1] > 0 && counts[2] > 0){
                res = min(res, p2 - p1 + 1);
                counts[S[p1] - '0']--;
                p1++;
                flag = false;
                continue;
            }
            
            p2++;
            flag = true;
        }
        
        if(res == INT_MAX) return -1;
        
        return res;
    }
};