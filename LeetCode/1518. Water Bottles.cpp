// DATE: 07-JUL-2024
// Question URL: https://leetcode.com/problems/water-bottles/description/

// Question: 1518. Water Bottles
// Description: There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

//              The operation of drinking a full water bottle turns it into an empty bottle.

//              Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.
// Approach: 1. Initially we have all water bottles filled so we can drink all of them.
//              Now all these bottles are emptied so we can exchange them for filled water bottles again we can drink the bottles and exchange this continues until we can't exchange water bottles further.
//              So initially we can drink numBottles of water, ans = ans + numBottles, now empty = empty + numBottles.
//              We can exchange empty bottles and get filled bottles of numBottles = empty / numExchange.
//              When empty bottles are not a multiple of numExchange we will be left with some empty bottles this is given by empty = empty % numExchange.
//              We can repeat above 3 steps until we don't have any bottles to drink i.e., numBottles = 0.

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, empty = 0;

        while(numBottles != 0){
            ans = ans + numBottles;
            empty += numBottles;

            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }

        return ans;
    }
};