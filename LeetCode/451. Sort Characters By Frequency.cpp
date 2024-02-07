// DATE: 07-FEB-2024
// Question URL: https://leetcode.com/problems/sort-characters-by-frequency/description/

// Question: 451. Sort Characters By Frequency
// Description: Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

//              Return the sorted string. If there are multiple answers, return any of them.
// Approach: 1. Have freq in map, push them on max heap (heapify based on freq). Then get max from heap and replace chars in string.

class compare{
    public:
        bool operator()(pair<char, int> p, pair<char, int> q){
            if(p.second < q.second) return true;
            return false;
        }
};

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
        int l = 0;

        for(int i = 0; i < s.length(); ++i){
            m[s[i]]++;
        }

        for(auto it: m){
            pq.push({it.first, it.second});
        }

        while(!pq.empty()){
            pair<char, int> p = pq.top();
            pq.pop();
            for(int i = 0; i < p.second; ++i) s[l++] = p.first;
        }

        return s;
    }
};