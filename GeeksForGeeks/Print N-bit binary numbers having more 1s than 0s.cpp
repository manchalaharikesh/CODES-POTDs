// DATE: 25-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
// Question: Print N-bit binary numbers having more 1s than 0s
// Description: Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.
// Approach: 1. For all valid numbers with n bits, generate their binary strings and verify if any prefix has more 0s than 1s if not append it to ans.

class Solution{
public:	
    string validateAndGetString(int n, bool& flag){
        int zero = 0, one = 0;
        string s = "";
        
        while(n != 0){
            if(n % 2 == 0) s = "0" + s;
            else s = "1" + s;
            
            n /= 2;
        }
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') zero++;
            else if(s[i] == '1') one++;
            
            if(zero > one){
                flag = false;
                break;
            }
        }
        
        return s;
    }
    
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    bool flag;
	    string s;
	    
	    for(int i = 1 << (n-1); i < (1 << n); i++){
	        flag = true;
	        s = validateAndGetString(i, flag);
	        if(flag) ans.push_back(s);
	    }
	    
	    reverse(ans.begin(), ans.end());
	    
	    return ans;
	}
};