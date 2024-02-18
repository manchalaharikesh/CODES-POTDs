// DATE: 19-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/game-with-string4100/1
// Question: Game with String
// Description: Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. 
// Approach: 1. Store the frequency of chars into a max-heap. Let p is 1st top and q is 2nd top in heap. Then until k != 0 do decrease k = p.freq-q.freq+1 and p.freq to q.freq-1 for valid k, otherwise p.freq decreased to p.freq-k and k = 0.

class Compare{
    public:
    bool operator()(pair<int, int> p, pair<int, int> q){
        return p.second < q.second;
    }
};

class Solution{
public:
    int minValue(string s, int k){
        map<char, int> m;
        vector<pair<int, int>> v;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++) m[s[i] - 'a']++;
        for(auto it: m){
            pq.push({it.first, it.second});
        }
        
        while(k != 0){
            pair<int, int> p = pq.top();
            pq.pop();
            pair<int, int> top = pq.top();
            
            if(k >= p.second - top.second + 1){
                k = k - (p.second - top.second + 1);
                p.second = top.second - 1;
            }
            else{
                p.second = p.second - k;
                k = 0;
            }
            pq.push(p);
        }
        
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            ans = ans + p.second * p.second;
            pq.pop();
        }
        
        return ans;
    }
};