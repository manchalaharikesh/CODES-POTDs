// DATE: 25-SEP-2023
// Question URL: https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1
// Question: Maximum Sum Combination
// Description: Given two arrays A & B of size N find K pairs of maximum sums from elements of A & B.
// Approach: 1. Sort the arrays in descending order.
//              Then use a max heap to store the sum for every element in A with 0th position in B.
//              Then find the K maximum sums possible whose logic to be understood from below code.

class Compare{
    public:
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        return a.second < b.second;
    }
};

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int> ans;
        
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Compare> pq;

        for (int i = 0; i < N; i++) {
          pq.push({{i, 0}, A[i] + B[0]});
        }
        
        while(true){
            pair<pair<int, int>, int> p1 = pq.top();
            pq.pop();
            
            pair<pair<int, int>, int> p2 = pq.top();
            
            int i = p1.first.first, j = p1.first.second + 1;
            ans.push_back(p1.second);
            K--;
            
            while(j < N && A[i] + B[j] >= p2.second && K > 0){
                ans.push_back(A[i] + B[j]);
                j++;
                K--;
            }
            
            if(K == 0) break;
            if(j < N) pq.push({{i, j}, A[i] + B[j]});
        }

        return ans;
    }
};