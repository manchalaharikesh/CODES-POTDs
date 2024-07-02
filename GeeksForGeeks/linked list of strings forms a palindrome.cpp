// DATE: 02-JUL-2024
// Question URL: https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1
// Question: linked list of strings forms a palindrome
// Description: Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.
// Approach: 1. Iterate the linked list and create the whole string, then apply palindrome algo on the string created.

/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        string s = "";
        
        while(head != NULL){
            s += head->data;
            
            head = head->next;
        }
        
        for(int i = 0; i <= s.length() / 2; i++){
            if(s[i] != s[s.length()-i-1]) return false;
        }
        
        return true;
    }
};