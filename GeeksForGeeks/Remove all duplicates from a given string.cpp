// DATE: 10-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
// Question: Remove all duplicates from a given string
// Description: Given a string str which may contains lowercase and uppercase chracters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution{
public:
	string removeDuplicates(string str) {
	    bool arr[52] = {false};
	    int idx;
	    string ans = "";
	    
	    for(int i = 0; i < str.length(); i++){
	        if(str[i] <= 'Z') idx = str[i] - 'A';
	        else idx = 26 + str[i] - 'a';
	        
	        if(!arr[idx]){
	            ans += str[i];
	            arr[idx] = true;
	        }
	    }
	    
	    return ans;
	}
};