// DATE: 12-OCT-2023
// Question URL: https://leetcode.com/problems/find-in-mountain-array/

// Question: 1095. Find in Mountain Array
// Description: You may recall that an array arr is a mountain array if and only if:

//              arr.length >= 3
//              There exists some i with 0 < i < arr.length - 1 such that:
//              arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//              arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//              Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

//              You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

//              MountainArray.get(k) returns the element of the array at index k (0-indexed).
//              MountainArray.length() returns the length of the array.
//              Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.thm with O(log n) runtime complexity.
// Approach: 1. Binary Serach.

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n-1, mid = 0, maxIdx = -1;

        while(high != low + 1){
            mid = low + (high - low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                maxIdx = mid+1;
                low = mid;
            }
            else{
                maxIdx = mid;
                high = mid;
            }
        }

        if(mountainArr.get(high) == target) return high;

        int ans = bsLeft(mountainArr, target, 0, high-1);
        if(ans == -1) ans = bsRight(mountainArr, target, high+1, n-1);

        return ans;
    }

    int bsLeft(MountainArray &mountainArr, int target, int low, int high){
        int mid;

        while(low <= high){
            mid = low + (high - low)/2;
            int val = mountainArr.get(mid);

            if(val == target) return mid;
            else if(val < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;
    }

    int bsRight(MountainArray &mountainArr, int target, int low, int high){
        int mid;

        while(low <= high){
            mid = low + (high - low)/2;
            int val = mountainArr.get(mid);

            if(val == target) return mid;
            else if(val < target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return -1;
    }
};