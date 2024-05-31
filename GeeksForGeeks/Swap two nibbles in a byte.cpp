// DATE: 31-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

// Question: Swap two nibbles in a byte
// Description: Given a number n, Your task is to swap the two nibbles and find the resulting number. 

//              A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. This byte can be divided into two nibbles: 1001 and 0110.
// Approach: 1. Code is Self-Explanatory.

class Solution {
  public:
    int swapNibbles(int n) {
        int ans = n >> 4;
        
        for(int i = 0; i < 4; i++){
            if(n & (1 << i)){
                ans = ans | (1 << (4 + i));
            }
        }
        
        return ans;
    }
};