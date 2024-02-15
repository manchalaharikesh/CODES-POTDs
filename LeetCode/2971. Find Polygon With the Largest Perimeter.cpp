// DATE: 15-FEB-2024
// Question URL: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

// Question: 2971. Find Polygon With the Largest Perimeter
// Description: You are given an array of positive integers nums of length n.

//              A polygon is a closed plane figure that has at least 3 sides. The longest side of a polygon is smaller than the sum of its other sides.

//              Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, then there always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.

//              The perimeter of a polygon is the sum of lengths of its sides.

//              Return the largest possible perimeter of a polygon whose sides can be formed from nums, or -1 if it is not possible to create a polygon.
// Approach: 1. Sort nums in ascending order, then have a prefix sum array. If for i in (n-1 to 1) nums[i] < pre[i-1] we found ans as pre[i].

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long long> pre(nums.size(), 0);
        int p1 = nums.size() - 1;
        long long ans = -1;
        sort(nums.begin(), nums.end());

        pre[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            pre[i] = pre[i-1] + nums[i];
        }

        while(p1 > 1){
            if(pre[p1-1] > nums[p1]){
                ans = pre[p1];
                break;
            }
            p1--;
        }

        return ans;
    }
};