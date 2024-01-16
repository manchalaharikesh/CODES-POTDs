// DATE: 16-JAN-2024
// Question URL: https://leetcode.com/problems/insert-delete-getrandom-o1/description/

// Question: 380. Insert Delete GetRandom O(1)
// Description: Implement the RandomizedSet class:

//              RandomizedSet() Initializes the RandomizedSet object.
//              bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
//              bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
//              int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
//              You must implement the functions of the class such that each function works in average O(1) time complexity.
// Approach: 1. Use hashmap and rand() for implementation.

class RandomizedSet {
public:
    map<int, int> m;
    int c;
    RandomizedSet() {
        c = 0;
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()){
            m[val] = 1;
            c++;
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            m.erase(val);
            c--;
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        auto randItr = next(m.begin(), rand() % c);
        return randItr->first;
    }
};