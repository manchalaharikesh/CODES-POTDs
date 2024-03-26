// DATE: 26-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/additive-sequence/1
// Question: Additive sequence
// Description: Given a string n, your task is to find whether it contains an additive sequence or not. A string n contains an additive sequence if its digits can make a sequence of numbers in which every number is addition of previous two numbers. You are required to complete the function which returns true if the string is a valid sequence else returns false. For better understanding check the examples.

//              Note: A valid string should contain at least three digit to make one additive sequence. 
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution {
  public:
    string add(string n1, string n2){
        int i = n1.length()-1, j = n2.length()-1, c = 0;
        string ans = "";
        
        for(; i >= 0 || j >= 0; i--, j--){
            if(i >= 0 && j >= 0) c = c + (n1[i]-'0') + (n2[j]-'0');
            else if(i >= 0) c = c + (n1[i]-'0');
            else c = c + (n2[j]-'0');
            ans = char(c%10 + 48) + ans;
            c = c/10;
        }
        
        if(c != 0) ans = char(c + 48) + ans;

        return ans;
    }
    
    bool isValidSequence(string n, string sum, int p){
        for(int i = 0; i < sum.length() && i + p < n.length(); i++){
            if(sum[i] != n[i+p]) return false;
        }
        return true;
    }
    
    bool isAdditiveSequence(string n) {
        string n1 = "", n2 = "", t1 = "", t2 = "", sum = "";
        int p = 0;
        
        for(int i = 0; i < n.length()-2; i++){
            n1 += n[i];
            n2 = "";
            for(int j = i+1; j < n.length()-1; j++){
                n2 += n[j];
                
                t1 = n1;
                t2 = n2;
                p = n1.length() + n2.length();
                
                while(p + max(t1.length(), t2.length()) <= n.length()){                
                    sum = add(t1, t2);
                    if(isValidSequence(n, sum, p)){
                        t1 = t2;
                        t2 = sum;
                        p = p + sum.length();
                    }
                    else{
                        break;
                    }
                }
                if(p == n.length()) return true;
            }
        }
        
        return false;
    }
};