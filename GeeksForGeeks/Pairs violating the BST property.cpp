// DATE: 01-APR-2024
// Question URL: https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1

// Question: Pairs violating the BST property
// Description: Given a binary tree with n nodes, find the number of pairs violating the BST property.
//               BST has the following properties:-

//              Every node is greater than its left child and less than its right child.
//              Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
//              The maximum in the left sub-tree must be less than the minimum in the right subtree.

// Approach: 1. The inorder of a BST must be in sorted order. If the given tree has violating pairs for BST properties we dont have its inorder sorted.
//              So we sort it with merge sort. And while arr[i] < arr[j] it means jth element is smaller than (mid-i+1) elements.
//              Thus for jth element it has (mid-i+1) pairs to violate BST properties. Do it for all element swaps which is the required ans.

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& arr){
        if(root == NULL) return;
        
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    void merge(vector<int>& arr, int n, int& c, int low, int mid, int high){
        vector<int> copy(high-low+1);
        int i = low, j = mid + 1, k = 0;
        while(i <= mid && j <= high){
            if(arr[i] <= arr[j]){
                copy[k] = arr[i];
                i++;
            }
            else{
                copy[k] = arr[j];
                c += (mid-i+1);
                j++;
            }
            k++;
        }
        
        while(i <= mid){
            copy[k] = arr[i];
            i++;
            k++;
        }
        while(j <= high){
            copy[k] = arr[j];
            j++;
            k++;
        }
        
        k = 0;
        while(k < high-low+1){
            arr[low+k] = copy[k];
            k++;
        }
    }
    
    void mergeSort(vector<int>& arr, int n, int& c, int low, int high){
        if(low < high){
            int mid = low + (high - low) / 2;
            mergeSort(arr, n, c, low, mid);
            mergeSort(arr, n, c, mid + 1, high);
            merge(arr, n, c, low, mid, high);
        }
    }
    
    int pairsViolatingBST(int n, Node *root) {
        vector<int> arr;
        int c = 0;
        
        inorder(root, arr);
        
        mergeSort(arr, n, c, 0, n-1);
        
        return c;
    }
};