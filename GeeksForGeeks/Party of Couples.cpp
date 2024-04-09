// DATE: 10-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/alone-in-couple5507/1
// Question: Party of Couples
// Description: You are given an integer array arr[] of size n, representing n number of people in a party, each person is denoted by an integer. Couples are represented by the same number ie: two people have the same integer value, it means they are a couple. Find out the only single person in the party of couples.

//              NOTE: It is guarantee that there exist only one single person in the party.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution{
    public:
    int findSingle(int n, int arr[]){
        for(int i = 1;  i < n; i++){
            arr[0] = arr[0] ^ arr[i];
        }
        
        return arr[0];
    }
};