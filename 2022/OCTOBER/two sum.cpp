PROBLEM: https://leetcode.com/problems/two-sum/

/*
initial approach
pseudpo code:
1.run two for loops 
2.if a[i]+a[j]==target push i,j in a vector and return 

tc:O(n^2) //since we are using two for loops
sc:O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
          for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
              ans.push_back(i);
              ans.push_back(j);
              return ans;
            }
          }
        }
      return ans;
    }
};

/*
optimised
using hashing
best explaination(striver bhaiya):https://www.youtube.com/watch?v=dRUpbt8vHpo
tc: O(n) //for loop +O(1)//for insertion and searching in an unordered map
sc:O(n) //for storing in map
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
          if(mp.find(target-nums[i])!=mp.end()){
            ans.push_back(mp[target-nums[i]]);
            ans.push_back(i);
            return ans;
          }
          mp[nums[i]]=i;
        }
        return ans;
    }
};
