// DATE: 04-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1
// Question: Binary representation of next number
// Description: Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.
// Approach: 1. When we add 1 to existing number then in its binary representation all 1s are turned 0 until we find a 0 and turn it 1.
//              E.g.: 1011 be current number the next number is 1100.
//              Code is Self-Explanatory.

class Solution {
  public:
    string removeTrailing(string s){
        string temp = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0' && temp == "") continue;
            temp = temp + s[i];
        }
        
        return temp;
    }
    string binaryNextNumber(string s) {
        int i = s.length()-1;
        
        while(i >= 0){
            if(s[i] == '0'){
                s[i] = '1';
                break;
            }
            else{
                s[i] = '0';
            }
            i--;
        }
        
        s = i >= 0 ? s : '1' + s;
        s = removeTrailing(s);
        
        return s;
    }
};