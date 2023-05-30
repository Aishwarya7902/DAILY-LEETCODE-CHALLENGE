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

/*
using vector
*/

class MyHashSet {
public:
    
    
   vector<bool>v;
    MyHashSet() : v(1e6+1,false){ }
    
    
    void add(int key) {
        v[key]=true;   
    }
    
    void remove(int key) {
        v[key]=0;
        
    }
    
    bool contains(int key) {
       
        return v[key];
        
    }
};

