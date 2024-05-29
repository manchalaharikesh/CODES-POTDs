// DATE: 29-MAY-2024
// Question URL: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/

// Question: 1404. Number of Steps to Reduce a Number in Binary Representation to One
// Description: Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

//              If the current number is even, you have to divide it by 2.

//              If the current number is odd, you have to add 1 to it.

//              It is guaranteed that you can always reach one for all test cases.
// Approach: 1. The main idea here is when we have a odd number like 110011 when we convert it to even number by adding 1, we observe the new binary form for even number is 110100.
//              This shows that when we inc a number by 1 all the 1s are converted to 0 until we get a 0 and this first 0 will be turned into 1.
//              Now from above operations in given question, we inc our answer counter c by 1 when we have a LSB as 0 (divide it by 2 is counted as one operation).
//              And when our LSB is 1 we inc c by 1 for making number even.
//              Also when converting number to even in above process we need to change 1s to 0s until we get a 0 and convert it to 1.
//              Thus parallely we inc c while converting 1s to 0s as in future we divide them by 2 (LSB as 0 makes them even numbers).
//              e.g: 1100111 -> 1101000 (we in future divide the number by 2 for being even for 3 times as it has three 0s).

class Solution {
public:
    int numSteps(string s) {
        int c = 0;
        int i = s.length()-1;

        while(i >= 0 && s[i] == '0'){
            c++;
            i--;
        }

        while(i >= 0 && s[i] =='1'){
            if(i == 0 && s[i] == '1') break;
            c++;
            while(i >= 0 && s[i] == '1'){
                c++;
                i--;
            }
            if(i >= 0) s[i] = '1';
        }

        return c;
    }
};