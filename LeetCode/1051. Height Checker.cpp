// DATE: 10-JUN-2024
// Question URL: https://leetcode.com/problems/height-checker/description/

// Question: 1051. Height Checker
// Description: A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

//              You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

//              Return the number of indices where heights[i] != expected[i].
// Approach: 1. Store given heights into another vector expected. Now sort heights.
//              Now iteerate both the vectors to find number of positions are not matching (i.e., heights[i] != expected[i]).

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        int c = 0;

        sort(heights.begin(), heights.end());
        for(int i = 0; i < heights.size(); i++){
            if(expected[i] != heights[i]) c++;
        }

        return c;
    }
};