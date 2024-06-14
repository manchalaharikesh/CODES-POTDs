// DATE: 14-JUN-2024
// Question URL: https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

// Question: 945. Minimum Increment to Make Array Unique
// Description: You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

//              Return the minimum number of moves to make every value in nums unique.

//              The test cases are generated so that the answer fits in a 32-bit integer.
// Approach: 1. We need to replace the number (repeating) that is always nearest and greatest to the current number.
//              Thus we initially store the elements in a map with its frequency. Then we iterate the map, if the element has freq more than 1, we need to replace the elements with nearest greater element.
//              The major advantage is, as the map makes elements in a sorted way, we look for nearest numbers to substitute in a linear iteration.
//              i.e., let say for 2 we found 6 as element then for 3 the replacable element is no way less than 6 so we prevent looking back 4, 5 again.

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> m;
        int ans = 0, x = -1;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }

        for(auto it: m){
            if(x < it.first) x = it.first + 1;

            while(it.second > 1){
                if(m.find(x) == m.end()){
                    it.second--;
                    m[x]++;
                    ans = ans + x - it.first;
                }

                x++;
            }
        }

        return ans;
    }
};