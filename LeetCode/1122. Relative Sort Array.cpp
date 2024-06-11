// DATE: 11-JUN-2024
// Question URL: https://leetcode.com/problems/relative-sort-array/description/

// Question: 1122. Relative Sort Array
// Description: Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

//              Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
// Approach: 1. In this problem we need to sort the elements common in both arr1 and arr2 with reference to their order of occurence in arr2.
//              The extra elements in arr1 need to be present in ascending order at the end.
//              For this we can store the freq of elements of arr1 in a map.
//              Then for every element ele in arr2, we insert ele for m[ele] times into ans vector and mark m[ele] = 0.
//              Now after this to deal with extra elements of arr1, we iterate map m, and the advantage is while iterating the map m, the keys are always in sorted order, then we insert these extra elements ele of map with m[ele] > 0 into ans for m[ele] times.

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        int k = 0;

        for(int i = 0; i < arr1.size(); i++){
            m[arr1[i]]++;
        }

        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < m[arr2[i]]; j++){
                arr1[k] = arr2[i];
                k++;
            }
            m[arr2[i]] = 0;
        }

        for(auto it: m){
            for(int j = 0; j < it.second; j++){
                arr1[k] = it.first;
                k++;
            }
        }

        return arr1;
    }
};