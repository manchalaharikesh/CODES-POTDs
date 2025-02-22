// DATE: 22-FEB-2025
// Question URL: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

// Question: 1028. Recover a Tree From Preorder Traversal
// Description: We run a preorder depth-first search (DFS) on the root of a binary tree.

//              At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

//              If a node has only one child, that child is guaranteed to be the left child.

//              Given the output traversal of this traversal, recover the tree and return its root.
// Approach: 1. Traverse the given string, for every '-' encountered increase the depth variable d,
//              for every first instance of digit (iterate to get all the digits until we encounter '-' or reach end of string),
//              then create a node with current number and add it to map as m[d] = nn (newly created node).
//              Then to add it to its parent the logic is: as the string is in preorder traversal until a parent's left subtree
//              is completed, we never iterate its right subtree or its ansector's right subtree.
//              So at an instance there is only one valid node at depth d-1 to be parent of current node, thus parent is at m[d-1].
//              If left child of m[d-1] is NULL m[d-1]->left = nn or else m[d-1]->right = nn.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        map<int, TreeNode*> m;
        int d = 0, n = traversal.length(), num = 0;

        for(int i = 0; i < n; i++){
            if(traversal[i] != '-'){
                while(i < n && traversal[i] != '-'){
                    num = num * 10 + traversal[i] - '0';
                    i++;
                }
                TreeNode *nn = new TreeNode(num);
                m[d] = nn;
                if(d > 0){
                    if(m[d-1]->left == NULL) m[d-1]->left = nn;
                    else m[d-1]->right = nn;
                }
                d = 1;
                num = 0;
            }
            else{
                d++;
            }
        }

        return m[0];
    }
};