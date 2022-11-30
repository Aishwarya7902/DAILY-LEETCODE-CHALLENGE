PROBLEM:https://leetcode.com/problems/unique-number-of-occurrences/
video:

/*
MY INITIAL APPROACH
//tc:O(n)
//sc:O(n)
pseudo code
1.store frequency of each element in a map
2.store all the values of map in a set
3.if all values are unique...then map and set will have same size
4.if map and set have a different size , then it means that some keys have 
similar values in the map...hence occrances are not unique
*/

class Solution {
public:
 
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
      set<int>s;
      for(auto it:arr){
        mp[it]++;
      }
      
      for(auto it:mp){
        s.insert(it.second);
      }
      return s.size()==mp.size();
      
    }
};
