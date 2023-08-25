// DATE: 25-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/multiply-two-strings/1

// Question: Multiply Two Strings
// Description: Given two integer strings return a string by that is the multiplication of them. 
// Approach: 1. Brute Force.

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        bool isNeg = false, flag = true;
        int n1, n2;
        int val = 0, c = 0;
        string ans = "";
        
        if(s1[0] == '-' && s2[0] == '-') isNeg = false;
        else if(s1[0] == '-' || s2[0] == '-') isNeg = true;
        
        s1 = removeTrailingZeros(s1);
        s2 = removeTrailingZeros(s2);
        
        n1 = s1.length();
        n2 = s2.length();
        
        vector<int> mat(n1 + n2, 0);
        vector<bool> hasVal(n1 + n2, false);
        
        for(int j = 0; j < n2; j++){
            int i = 0;
            for(; i < n1; i++){
                if(isdigit(s1[n1-1-i]) && isdigit(s2[n2-1-j])){
                    val = c + mat[n1+n2-1-(j+i)] + (s1[n1-1-i] - '0')*(s2[n2-1-j] - '0');
                    c = val / 10;
                    val = val % 10;
                    mat[n1+n2-1-(j+i)] = val;
                    hasVal[n1+n2-1-(j+i)] = true;
                }
            }
            
            if(c != 0){
                mat[n1+n2-1-(j+i)] = c;
                hasVal[n1+n2-1-(j+i)] = true;
                c = 0;   
            }
        }
        
        if(c != 0) ans = char(c+48) + ans;
        
        for(int i = 0; i < n1 + n2; i++){
            if(hasVal[i]) ans = ans + char(mat[i]+48);
        }
        
        ans = isNeg ? "-" + ans : ans;
        
        return ans;
    }
    
    string removeTrailingZeros(string s){
        bool flag = true;
        string ans = "";
        int i = 0;
        
        if(s[0] == '-') i++;
        
        for(; i < s.length(); i++){
            if(s[i] == '0' && flag){
                continue;
            }
            else{
                flag = false;
            }
            ans = ans + s[i];
        }

        return ans;
    }
};