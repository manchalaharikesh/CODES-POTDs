// DATE: 12-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1
// Question: Count numbers containing 4
// Description: You are given a number n, Return the count of total numbers from 1 to n containing 4 as a digit.
// Approach: 1. Code is Self-Explanatory.

class Solution {
  public:
    int countNumberswith4(int n) {
        int ans = 0, temp;
        
        for(int i = 1; i <= n; i++){
            temp = i;
            while(temp != 0){
                if(temp % 10 == 4){
                    ans++;
                    break;
                }
                temp /= 10;
            }
        }
        
        return ans;
    }
};