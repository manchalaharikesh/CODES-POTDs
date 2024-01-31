// DATE: 31-JAN-2024
// Question URL: https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1
// Question: Insert and Search in a Trie
// Description: Complete the Insert and Search functions for a Trie Data Structure. 

//              Insert: Accepts the Trie's root and a string, modifies the root in-place, and returns nothing.
//              Search: Takes the Trie's root and a string, returns true if the string is in the Trie, otherwise false.
//              Note: To test the correctness of your code, the code-judge will be inserting a list of N strings called into the Trie, and then will search for the string key in the Trie. The code-judge will generate 1 if the key is present in the Trie, else 0.
// Approach: 1. Code Self-Explanatory.

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/
class Solution
{
    public:
        int idx = 0;
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            if(idx == key.length()){
                root->isLeaf = true;
                return ;
            }
            if(root->children[key[idx] - 'a'] == NULL)
                root->children[key[idx] - 'a'] = getNode();
                
            idx++;
            insert(root->children[key[idx-1] - 'a'], key);
            idx--;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            if(idx == key.length() && root->isLeaf) return true;
            if(root->children[key[idx] - 'a'] == NULL) return false;
            
            idx++;
            if(!search(root->children[key[idx-1] - 'a'], key)) return false;
            idx--;
            
            return true;
        }
};