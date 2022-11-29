PROBLEM:https://leetcode.com/problems/insert-delete-getrandom-o1/

VIDEO:https://www.youtube.com/watch?v=cExIVl6MC3g

class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))
          return false;
        arr.push_back(val);
        mp[val]=arr.size()-1;
      return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
          int ind=mp[val];
          int v=arr.back();
          arr.pop_back();
          arr[ind]=v;
          mp[v]=ind;
          mp.erase(val);
          return true;
        }
      return false;
    }
    
    int getRandom() {
       return arr[rand()%arr.size()]; 
    }
};
