PROBLEM :https://leetcode.com/problems/design-hashset/description/

VIDEO:

/*
SELF
TC:O(1)
SC:O(N)
*/

class MyHashSet {
public:
    unordered_map<int,int>mp;
    MyHashSet() {
        
    }
    
    void add(int key) {
        mp[key]++;
        
    }
    
    void remove(int key) {
        mp.erase(key);
        
    }
    
    bool contains(int key) {
        if(mp.find(key)==mp.end())return false;
        return true;
        
    }
};
