// DATE: 10-OCT-2023
// Question URL: https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

// Question: Nodes at given distance in binary tree
// Description: Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.
//              Note:

//              You have to return the list in sorted order.
//              The tree will not contain duplicate values.
// Approach: 1. For a given tree and target when you find the target node from root mark the distance from curr node to target node in hashmap. From each node in hashmap find the nodes at distance k - currDist.

class Solution
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        map<Node*, int> hm;
        int dist = 0;
        vector<int> ans;
        
        updateDistances(root, target, hm, dist);
        
        for(auto i = hm.begin(); i != hm.end(); i++){
            if(k - i->second >= 0) findNodes(i->first, k - i->second, ans, hm);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    
    void updateDistances(Node* root, int target, map<Node*, int>& hm, int& dist){
        
        if(root == NULL) return;
        
        else if(root->data == target){
            hm[root] = dist;
            dist++;
            return;
        }    
        
        if(dist == 0) updateDistances(root->left, target, hm, dist);
        if(dist == 0) updateDistances(root->right, target, hm, dist);
        
        if(dist > 0){
            hm[root] = dist;
            dist++;
        }
    }
    
    void findNodes(Node* root, int dist, vector<int>& ans, map<Node*, int> hm){
        if(root == NULL) return;
        
        if(dist == 0){
            ans.push_back(root->data);
            return;
        }
        
        if(hm.find(root->left) == hm.end()) findNodes(root->left, dist-1, ans, hm);
        if(hm.find(root->right) == hm.end()) findNodes(root->right, dist-1, ans, hm);
    }
    
};