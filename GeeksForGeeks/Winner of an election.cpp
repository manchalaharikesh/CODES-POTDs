// DATE: 30-DEC-2023
// Question URL: https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1
// Question: Winner of an election
// Description: Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received the maximum count of votes. If there is a draw between two candidates, then print lexicographically smaller name.
// Approach: 1. Store frequency into a map then iterate it as per given requirements.

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string, int> m;
        int votes = 0;
        string name;
        vector<string> ans;
        
        for(int i = 0; i < n; i++){
            if(m.find(arr[i]) != m.end()){
                m[arr[i]]++;
            }
            else{
                m[arr[i]] = 1;
            }
        }
        
        for(auto i: m){
            if(votes < i.second){
                votes = i.second;
                name = i.first;
            }
            else if(votes == i.second and name > i.first){
                name = i.first;
            }
        }
        
        ans.push_back(name);
        ans.push_back(to_string(votes));
        
        return ans;
    }
};