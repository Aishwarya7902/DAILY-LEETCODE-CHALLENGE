PROBLEM:https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/
VIDEO:https://www.youtube.com/watch?v=tofpb5rIwRk

/*
  recursion 
  TC: since at every index we have three options that is to say we can applly one out of the three rules
  hence TC will be O(3^n)
  SC:
*/

class Solution {
public:
    int n;
    bool solve(int indx,vector<int>& nums){
        if(indx>=n){
            return true;
        }
        bool result=false;

        //rule-1
        if(indx+1<n && nums[indx]==nums[indx+1]){
            result=solve(indx+2,nums);
        }
        if(result==true)
         return result;

        //rule-2
        if(indx+2 <n && nums[indx]==nums[indx+1] && nums[indx+2]==nums[indx+1]){
            result=solve(indx+3,nums);
        }
        if(result==true)
         return result;

        //rule-3
        if(indx+2 <n && (nums[indx+1]-nums[indx]==1) &&(nums[indx+2]-nums[indx+1]==1)){
            result=solve(indx+3,nums);
        }
        if(result==true)
         return result;



      return result;  
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        return solve(0,nums);
    }
};

/*

MEMOIZATION
TC: since we have total n states to visit ....hence TC is :O(n)
  */

class Solution {
public:
    int n;
    int t[100001];
    bool solve(int indx,vector<int>& nums){
        if(indx>=n){
            return true;
        }
        if(t[indx]!=-1)return t[indx];
        bool result=false;

        //rule-1
        if(indx+1<n && nums[indx]==nums[indx+1]){
            result=solve(indx+2,nums);
        }
        if(result==true)
         return t[indx]=result;

        //rule-2
        if(indx+2 <n && nums[indx]==nums[indx+1] && nums[indx+2]==nums[indx+1]){
            result=solve(indx+3,nums);
        }
        if(result==true)
         return t[indx]=result;

        //rule-3
        if(indx+2 <n && (nums[indx+1]-nums[indx]==1) &&(nums[indx+2]-nums[indx+1]==1)){
            result=solve(indx+3,nums);
        }
        if(result==true)
         return t[indx]=result;



      return t[indx]=result;  
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};
