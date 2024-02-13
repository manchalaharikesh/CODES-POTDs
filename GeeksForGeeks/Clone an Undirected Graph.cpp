// DATE: 13-FEB-2024
// Question URL: https://www.geeksforgeeks.org/problems/clone-graph/1
// Question: Clone an Undirected Graph
// Description: Given a connected undirected graph with n nodes and m edges, with each node having a distinct label from 0 to n-1, create a clone of the graph. Each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

//              Note: If the user returns a correct copy of the given graph, then the system will print 1; in the case when an incorrect copy is generated or when the user returns the original node, the system will print 0.
// Approach: 1. Code - Self Explanatory.

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    void dfs(Node* node, map<int, Node*>& m){
        if(m.find(node->val) != m.end()) return ;
        
        m[node->val] = new Node(node->val);
        
        for(int i = 0; i < node->neighbors.size(); i++){
            dfs(node->neighbors[i], m);
            m[node->val]->neighbors.push_back(m[node->neighbors[i]->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        map<int, Node*> m;
        
        dfs(node, m);
        
        return m[node->val];
    }
};