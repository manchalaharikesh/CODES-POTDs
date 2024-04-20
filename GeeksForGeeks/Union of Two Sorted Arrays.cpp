// DATE: 20-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// Question: Union of Two Sorted Arrays
// Description: Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays.
// Approach: 1. Code is Self-Explanatory.

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        map<int, int> hm;
        int p1 = 0, p2 = 0;
        
        while(p1 < n && p2 < m){
            if(arr1[p1] == arr2[p2]){
                if(hm.find(arr1[p1]) == hm.end()) ans.push_back(arr1[p1]);
                hm[arr1[p1]] = 1;
                p1++;
                p2++;
            }
            else if(arr1[p1] < arr2[p2]){
                if(hm.find(arr1[p1]) == hm.end()) ans.push_back(arr1[p1]);
                hm[arr1[p1]] = 1;
                p1++;
            }
            else if(arr1[p1] > arr2[p2]){
                if(hm.find(arr2[p2]) == hm.end()) ans.push_back(arr2[p2]);
                hm[arr2[p2]] = 1;
                p2++;
            }
        }
        
        while(p1 < n){
           if(hm.find(arr1[p1]) == hm.end()) ans.push_back(arr1[p1]);
            hm[arr1[p1]] = 1;
            p1++;
        }
        while(p2 < m){
            if(hm.find(arr2[p2]) == hm.end()) ans.push_back(arr2[p2]);
            hm[arr2[p2]] = 1;
            p2++;
        }
        
        return ans;
    }
};