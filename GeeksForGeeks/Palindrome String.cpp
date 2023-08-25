// DATE: 25-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

// Question: Palindrome String.
// Description: For a given string verify if it is palindrome or not.
// Approach: 1. Two pointer technique from start and end and iterate until p1 < p2. If any time s[p1] != s[p2] return false.
//              At the end return true if control comes out of loop.

class Solution{
public:	
	
	int isPalindrome(string S)
	{
	    int p1 = 0, p2 = S.length()-1;
	    
	    while(p1 < p2){
	        if(S[p1] != S[p2]) return false;
	        p1++;
	        p2--;
	    }
	    
	    return true;
	}

};