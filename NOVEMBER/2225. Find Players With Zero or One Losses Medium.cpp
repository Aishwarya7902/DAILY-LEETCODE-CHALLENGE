PROBLEM:https://leetcode.com/problems/find-players-with-zero-or-one-losses/

#include<bits/stdc++.h>
class Solution {
  
  //tc: O(N)
  //sc:O(N)
public:
    vector<vector<int>> findWinners(vector<vector<int>>& match) {
        unordered_map<int,int>mp;
        vector<vector<int>>ans(2);
         set<int>s1,s2;
        
      int n=match.size();
      //registring all the losses
      for(int i=0;i<n;i++){
        mp[match[i][1]]++;
      }
      
      //searching all the players with zeroloss
      for(int i=0;i<n;i++){
        int x=match[i][0];
        if(mp.find(x)==mp.end()){
          s1.insert(x);
        }
      }
      
      //searching all the players with oneloss
      
      for(auto it:mp){
        if(it.second==1){
          s2.insert(it.first);
        }
      }
      
      /*NOTE:
      1.set s1 will contain all the players with zeroLoss
      2.set s2 will contain all the players with oneLoss
      */
      
      //push in ans
      for(auto it:s1){
       ans[0].push_back(it);
      }
      for(auto it:s2){
        ans[1].push_back(it);
      }
      
     
      
      
      //return ans
      return ans;
    }
};
