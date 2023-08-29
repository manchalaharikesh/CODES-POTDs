// DATE: 29-AUG-2023
// Question URL: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

// Question: Delete Nodes having greater values on right
// Description: For a given LL get only the nodes which have all nodes with lesser data values towards its left.
// Approach: 1. Have a stack push node if the top of stack value is greater than curr node value.
//           2. If top stack value is less than curr node value pop it.
//           3. Repeat step-1, 2 until LL is ended.
//           4. Now frame the LL from nodes in stack. 

class Solution
{
    public:
    Node *compute(Node *head)
    {
        stack<Node*> st;
        Node* temp = NULL;
        
        while(head != NULL){
            while(!st.empty() && head->data > st.top()->data) st.pop();
            st.push(head);
            head = head->next;
        }
        
        while(!st.empty()){
            st.top()->next = temp;
            temp = st.top();        
            
            st.pop();
        }
        
        return temp;
    }
    
};