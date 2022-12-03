PROBLEM:https://leetcode.com/problems/sort-characters-by-frequency/

/*METHOD 1:
TC:
SC:
pseudo code:
1.traverse and find frequency of each character and store in a map
2.now make a vector of pairs<char,int> and store all the values of map in the vector
3.now sort this vector based on a comparator in which we sort by value of map in decreasing order
4.now traverse the vector and  add to ans string   frequency times  of given character
5.return ans

*/

#include<bits/stdc++.h>
class Solution {  
public:
  static bool cmp(pair<char,int>&a,pair<char,int>&b){
    return a.second>b.second;
  }
    string frequencySort(string s) {
     unordered_map<char,int>freq;
      vector<pair<char,int>>res;
      string ans;
     for(auto x:s){
       freq[x]++;
     }
      //sort based on values in decreasing order
      for(auto it:freq){
        res.push_back(it);
      }
      sort(res.begin(),res.end(),cmp);
      
      for(auto it:res){
        int val=it.second;
        
          while(val--){
            ans+=it.first;
            
          }
        
        
      }
      return ans;
    }
};
