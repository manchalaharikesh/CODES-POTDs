// DATE: 01-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/help-nobita0532/1

// Question: Odd Even Problem
// Description: Given a string s of lowercase English characters, determine whether the summation of x and y is EVEN or ODD.
//              where:

//              x is the count of distinct characters that occupy even positions in the English alphabet and have even frequency. 
//              y is the count of distinct characters that occupy odd positions in the English alphabet and have odd frequency.
//              Ex: string = "ab" here 'a' has an odd(1) position in the English alphabet & has an odd(1) frequency in the string so a is odd but b has an even(2) position in the English alphabet & has odd(1) frequency so it doesn't count(since string doesn't have 2 b's) so the final answer x + y = 1+0 = 1(odd) would be "ODD".

//              Note: Return "EVEN" if the sum of x & y is even otherwise return "ODD".
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    string oddEven(string s) {
        int freq[26] = {0}, x = 0, y = 0;
        
        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 97]++;
        }
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                if((i+1)%2 == 0 && freq[i]%2 == 0){ 
                    x++;
                }
                else if((i+1)%2 == 1 && freq[i]%2 == 1){ 
                    y++;
                }
            }
        }
        
        return (x + y) % 2 == 0 ? "EVEN" : "ODD";
    }
};