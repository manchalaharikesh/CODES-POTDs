// DATE: 23-DEC-2023
// Question URL: https://www.geeksforgeeks.org/problems/count-element-occurences/1
// Question: Count More than n / k Occurences
// Description: Given an array arr of size N and an element k. The task is to find the 
//              count of elements in the array that appear more than n/k times.
// Approach: 1. Store elements into a map with freq. Then find the count of elements 
//              whose freq is greater than n/k.

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        map<int, int> m;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(m.find(arr[i]) == m.end()){
                m[arr[i]] = 1;
            }
            else{
                m[arr[i]]++;
            }
        }
        
        for(auto i: m){
            if(i.second > n/k) ans++;
        }
        
        return ans;
    }
};