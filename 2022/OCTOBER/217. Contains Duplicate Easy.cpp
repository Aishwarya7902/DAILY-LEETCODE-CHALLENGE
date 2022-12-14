PROBLEM:https://leetcode.com/problems/contains-duplicate/
/*
initial approach
tc:O(n^2)
sc:O(1)
pseudo code:
1.run 2 for loops
2.if(a[i]==a[j]) return true from there
3.none of them returns true ....return false at last
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      int n=nums.size();
      
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          if(nums[i]==nums[j])
            return true;
        }
      }
      return false;
    }
};

/*
optimised approach
tc: O(n)
sc:O(n)
pseudo code:
1.traverse in nums and store frequency of each element in a map
2.traverse map and if any key has value >1 return true;
3.else return true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int,int>mp;
      for(auto x:nums){
        mp[x]++;
      }
      for(auto it:mp){
        if(it.second>1)return true;
      }
      return false;
    }
};

/*method 3
tc:
sc:
pseudo code:
1.since set contains only unique elements hence its size will always be less than or equal to size of nums
if nums has duplicate elements then size of set will be less than nums ....if nums has all unique elements then set and nums will have same size
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      return nums.size()> set<int>(nums.begin(),nums.end()).size();  
    }
};

/*method 4
tc:
sc:
pseudo code:
1.sort the array
2.traverse and if any adjacent elements are equla ...return true;
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1])return true;
      }
      return false;
    }
};
