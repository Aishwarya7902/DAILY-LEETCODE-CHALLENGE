problem:https://leetcode.com/problems/contains-duplicate-ii/

/*
initial approach:
tc: O(n^2)
sc: O(1)
pseudo code:
1.run 2 for loops and if nums[i]==nums[j] && abs(i-j)<=k return true
3.after we have traversed all loop ...return false
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
          if(nums[i]==nums[j] && abs(i-j)<=k )return true;
        }
      } 
      return false;
    }
};

/*
otimisation
video:https://youtu.be/t46QZYmqfoo
tc:
sc:
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
         if(mp.count(nums[i])>0 && abs(mp[nums[i]]-i)<=k)return true;
         mp[nums[i]]=i;
       }
      return false;
    }
};
