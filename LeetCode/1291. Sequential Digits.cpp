// DATE: 02-FEB-2024
// Question URL: https://leetcode.com/problems/sequential-digits/description/

// Question: 1291. Sequential Digits
// Description: An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

//              Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
// Approach: 1. Code is Self-Explanatory.

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int n, digit, minCount = 0, maxCount = 0, temp;
        vector<int> v;
        
        n = low;
        while(n != 0){
            digit = n % 10;
            n /= 10;
            minCount++;
        }
        
        n = high;
        while(n != 0){
            n /= 10;
            maxCount++;
        }
        
        for(int c = minCount; c <= maxCount; c++){
            for(int idx = digit -1; idx + c < 10; idx++){
                temp = stoi(s.substr(idx, c));
                if(temp >= low && temp <= high){
                    v.push_back(temp);
                }
            }
            
            digit = 1;
        }
        
        return v; 
    }
};