// DATE: 04-OCT-2023
// Question URL: https://leetcode.com/problems/design-hashmap/

// Question: 706. Design HashMap
// Description: Design a HashMap without using any built-in hash table libraries.

//              Implement the MyHashMap class:

//              MyHashMap() initializes the object with an empty map.
//              void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
//              int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
//              void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

// Approach: 1. Use and array of required size (BRUTE FORCE).

class MyHashMap {
public:
    long v[1000001] = {-1};
    bool s[1000001] = {false};
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        v[key] = value;
        s[key] = true;
    }
    
    int get(int key) {
        return s[key] ? v[key] : -1;
    }
    
    void remove(int key) {
        v[key] = -1;
        s[key] = false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */