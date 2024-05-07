// DATE: 07-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1
// Question: Reverse Level Order Traversal
// Description: Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.
// Approach: 1. Get the level order traversal stored in a map, then reverse elements of each level. Now store them into a vector and reverse it all together.

/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void bfs(queue<pair<Node*, int>>& q, map<int, vector<int>>& m){
    if(q.empty()) return ;
    
    pair<Node*, int> p = q.front();
    q.pop();
    
    if(m.find(p.second) == m.end()) m[p.second] = vector<int>();
    m[p.second].push_back((p.first)->data);
    
    if((p.first)->left != NULL) q.push({(p.first)->left, p.second+1});
    if((p.first)->right != NULL) q.push({(p.first)->right, p.second+1});
    
    bfs(q, m);
}

vector<int> reverseLevelOrder(Node *root)
{
    queue<pair<Node*, int>> q;
    map<int, vector<int>> m;
    vector<int> ans;
    
    q.push({root, 0});
    bfs(q, m);
    
    for(auto it = m.begin(); it != m.end(); it++){
        reverse((it->second).begin(), (it->second).end());
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        for(int i = 0; i < (it->second).size(); i++){
            ans.push_back((it->second)[i]);
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}