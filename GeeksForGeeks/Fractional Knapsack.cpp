// DATE: 26-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// Question: Fractional Knapsack
// Description: Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
//              Note: Unlike 0/1 knapsack, you are allowed to break the item here. 
// Approach: 1. Sort the given values based on the worth per unit weight (i.e., sort by value/weight). Then add items to knapsack by greedy approach (i.e., if it has capacity to take whole item include it otherwise include the portion of worth and that can fit in knapsack).

/*
struct Item{
    int value;
    int weight;
};
*/

bool sortFun(struct Item Item1, struct Item Item2){
    double w1 = Item1.weight, v1 = Item1.value, w2 = Item2.weight, v2 = Item2.value;
    if(v1/w1 > v2/w2) return true;
    return false;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double worth = 0, weight, value;
        sort(arr, arr + n, sortFun);
        
        for(int i = 0; i < n && W != 0; i++){
            weight = arr[i].weight, value = arr[i].value;
            if(W >= weight){
                worth += value;
                W -= weight;
            }
            else if(W < arr[i].weight){
                worth = worth + (value/weight)*W;
                W = 0;
            }
        }
        
        return worth;
    }
        
};