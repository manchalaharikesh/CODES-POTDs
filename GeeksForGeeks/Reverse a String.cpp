// DATE: 27-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/reverse-a-string/1

// Question: Reverse a string.
// Description: Reverse a given string. 
// Approach: 1. Implement a two pointer technique and by moving from start and end, swap characters until start < end.

class Solution
{
    public:
    string reverseWord(string str)
    {
        int p1=0, p2=str.length()-1;
        char temp;
        while(p1<p2){
            temp=str[p1];
            str[p1]=str[p2];
            str[p2]=temp;
            p1++;
            p2--;
        }
        return str;
    }
};
