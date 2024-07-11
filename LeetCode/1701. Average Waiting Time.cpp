// DATE: 09-JUL-2024
// Question URL: https://leetcode.com/problems/average-waiting-time/description/

// Question: 1701. Average Waiting Time
// Description: There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

//              arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
//              timei is the time needed to prepare the order of the ith customer.
//              When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

//              Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.
// Approach: 1. For the 1st person the data be [a1, t1], then his/her waiting time is t1, so far total wait time is w = a1 + t1 (as to visualize as on a timeframe).
//              For the second person the data be [a2, t2], then if a2 >= w he has no trouble with previous order, so his wait time is t2 (w = a2 + t2 as to visualize as on a timeframe); otherwise w - a2 + t2 be his wait time and w = w + t2.
//              And above step is repeated for all other persons who arrive.
//              Dry Run the code for better understanding.

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = customers[0][0] + customers[0][1], ans = customers[0][1];

        for(int i = 1; i < customers.size(); i++){
            if(customers[i][0] >= wait){
                wait = customers[i][0] + customers[i][1];
                ans = ans + customers[i][1];
            }
            else{
                ans = ans + (wait - customers[i][0] + customers[i][1]);
                wait = wait + customers[i][1];
            }
        }

        return ans / customers.size();
    }
};