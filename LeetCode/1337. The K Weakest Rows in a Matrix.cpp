// DATE: 18-SEP-2023
// Question URL: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// Question: 1337. The K Weakest Rows in a Matrix
// Description: Given Matrix in which each row has 1s followed by 0s. 1s rep soldiers and 0s rep civilians
//              Find the k weakest rows where count1s(row[i]) < count1s(row[j]) and if count1s(row[i]) == count1s(row[j]) choose the lesser row as weaker.
// Approach: 1. Priority Queue (Min Heap).

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;

        for(int i = 0; i < mat.size(); i++){
            int c = 0;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1) c++;
                else break;  
            }

            pq.push(pair<int, int>(c, i));
        }

        while(k--){
            pair<int, int> p = pq.top();
            pq.pop();

            ans.push_back(p.second);
        }
        
        return ans;
    }
};