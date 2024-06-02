// DATE: 02-JUN-2024
// Question URL: https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1
// Question: Construct list using given q XOR queries
// Description: Given a list s that initially contains only a single value 0. There will be q queries of the following types:

//              0 x: Insert x in the list
//              1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
//              Return the sorted list after performing the given q queries.
// Approach: 1. In this problem we can find a pattern that a ith query with query[i][0] == 0, we must xor query[i][1] with all other query elements with query[i+1:q][0] == 1 towards its right i.e., query[i+1:q][1].
//              Thus in this approach we move from back and store every query[i][1] of query[i][0] == 1 in a _xor variable which is the xor of all such elements.
//              When we get a query[i][0] == 0 we make query[i][1] ^= _xor.
//              And as we initally have a 0 into list by default which means it is nothing but the _xor variable itself as 0 xor k (anything) is k.
//              Thus the end result is the sorted list of [_xor, {query[i][1] (such that query[i][0] == 0)}].

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        int _xor = 0;
        vector<int> ans;
        
        for(int i = q-1; i >= 0; i--){
            if(queries[i][0] == 1){
                _xor ^= queries[i][1];
            }
            else{
                queries[i][1] ^= _xor;
                ans.push_back(queries[i][1]);
            }
        }
        ans.push_back(_xor);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};