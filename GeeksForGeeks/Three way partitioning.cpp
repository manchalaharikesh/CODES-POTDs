// DATE: 21-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/three-way-partitioning/1

// Question: Three way partitioning
// Description: Given an array of size n and a range [a, b]. The task is to partition the array around the range such that the array is divided into three parts.
//              1) All elements smaller than a come first.
//              2) All elements in range a to b come next.
//              3) All elements greater than b appear in the end.
//              The individual elements of three sets can appear in any order. You are required to return the modified array.

//              Note: The generated output is 1 if you modify the given array successfully.

//              Geeky Challenge: Solve this problem in O(n) time complexity.
// Approach: 1. Find the number of elements in each range. Then mark their start and end boundaries. Then place elements into the boundary they belong to by updating their start index.

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void swap(vector<int>& a, int i, int p){
        int t = a[i];
        a[i] = a[p];
        a[p] = t;
    }
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int first = 0, second = 0, third = 0;
        int i = 0, j = 0, k = 0, l_i, l_j, l_k, u_i, u_j, u_k;
        
        for(int p = 0; p < array.size(); p++){
            if(array[p] < a) first++;
            else if(array[p] >= a && array[p] <= b) second++;
            else third++;
        }
        
        i = 0;
        j = first;
        k = first + second;
        
        l_i = i;
        l_j = j;
        l_k = k;
        u_i = i + first-1;
        u_j = j + second-1;
        u_k = k + third-1;
        
        for(int p = 0; p < array.size(); ){
            if(array[p] < a){
                if(p < l_i || p > u_i){
                    swap(array, i, p);
                    i++;
                }
                else{
                    p++;
                }
            }
            else if(array[p] >= a && array[p] <= b){
                if(p < l_j || p > u_j){
                    swap(array, j, p);
                    j++;
                }
                else{
                    p++;
                }
            }
            else{
                if(p < l_k || p > u_k){
                    swap(array, k, p);
                    k++;
                }
                else{
                    p++;
                }
            }
        }
    }
};