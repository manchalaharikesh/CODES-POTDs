// DATE: 21-MAR-2024
// Question URL: https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// Question: ZigZag Tree Traversal
// Description: Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
// Approach: 1. Store nodes with their level. Insert even levels of nodes into ans while at odd levels reverse nodes and insert into ans.

/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	queue<pair<Node*, int>> q;
    	stack<int> st;
    	vector<int> ans;
    	vector<pair<int, int>> nodes;
    	
    	q.push({root, 0});
    	
    	while(!q.empty()){
    	    nodes.push_back({q.front().first->data, q.front().second});
    	    
    	    if(q.front().first->left != NULL) q.push({q.front().first->left, q.front().second + 1});
    	    if(q.front().first->right != NULL) q.push({q.front().first->right, q.front().second + 1});
    	    
    	    q.pop();
    	}
    	
    	for(int i = 0; i < nodes.size(); i++){
    	    if(nodes[i].second % 2 == 1){
    	        st.push(nodes[i].first);
    	    }
    	    else{
    	        while(!st.empty()){
    	            ans.push_back(st.top());
    	            st.pop();
    	        }
    	        ans.push_back(nodes[i].first);
    	    }
    	}
    	while(!st.empty()){
    	   ans.push_back(st.top());
    	   st.pop();
    	}
    	
    	return ans;
    }
};