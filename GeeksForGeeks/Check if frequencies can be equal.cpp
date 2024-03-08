// DATE: 08-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/check-frequencies4211/1
// Question: Check if frequencies can be equal
// Description: Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

//              Note: The driver code print 1 if the value returned is true, otherwise 0.
// Approach: 1. Store frequencies of chars in a map. Have freq1 and freq2 as two variables. If there are more than two unique freqs return false, if only one unique freq return true, else handle all cases as described in code.

class Solution{
public:	
	bool sameFreq(string s)
	{
	    map<char, int> m;
	    int freq1 = -1, freq2 = -1, c1 = 0, c2 = 0;
	    
	    for(int i = 0; i < s.length(); i++){
	        m[s[i]]++;
	    }
	    
	    for(auto it: m){
	        if(freq1 == -1 || freq1 == it.second){
	            freq1 = it.second;
	            c1++;
	        }
	        else if(freq2 == -1 || freq2 == it.second){
	            freq2 = it.second;
	            c2++;
	        }
	        else{
	            return false;
	        }
	    }

        if(freq2 == -1) return true;
        
        // if absolute difference is equal to 1
        // deleting the greater freq should have only one such instance
        // deleting the lower freq means it should be the only instance
        // e.g.: aaabbcc (c1 ==1) and aabbc (freq2 == 1 && c2 == 1)
        if(abs(freq1-freq2) == 1){
            if(freq1 > freq2){
                return c1 == 1 || (freq2 == 1 && c2 == 1);
            }
            else{
                return c2 == 1 || (freq1 == 1 && c1 == 1);
            }
        }

        // if absolute differences are not equal to 1, 
        // means we can remove only the lower freq instance and 
        // also only one such instance to be possible
        // e.g.: aaabbbc
	    return (freq1 == 1 && c1 == 1) || (freq2 == 1 && c2 == 1);
	}
};