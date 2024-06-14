// DATE: 14-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1
// Question: Armstrong Numbers
// Description: You are given a 3-digit number n, Find whether it is an Armstrong number or not.

//              An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371. 
//              Note: Return "true" if it is an Armstrong number else return "false".
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    string armstrongNumber(int n) {
        int temp1 = n, temp2 = 0, t;
        
        while(temp1 != 0){
            t = temp1 % 10;
            temp2 = temp2 + t*t*t;
            temp1 /= 10;
        }
        
        return temp2 == n ? "true" : "false";
    }
};