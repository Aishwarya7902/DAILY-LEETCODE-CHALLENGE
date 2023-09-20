PROBLEM :https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/?envType=daily-question&envId=2023-09-20
VIDEO :https://www.youtube.com/watch?v=w7u9sMlx7zc


/*

  tc:o(n)
  sc:o(n)

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int n=nums.size();
       unordered_map<int,int>mp;
       int sum=0;
       mp[0]=-1;
       for(int i=0;i<n;i++){
           sum+=nums[i];
           mp[sum]=i;
       }
       if(sum<x)return -1;
       int remainingSum=sum-x;
       int longestSubarray=INT_MIN;
       sum=0;
       for(int i=0;i<n;i++){
           sum+=nums[i];
           int findSum=sum-remainingSum;
           if(mp.find(findSum)!=mp.end()){
               int indx=mp[findSum];
               longestSubarray=max(longestSubarray,i-indx);
           }
       }
       return longestSubarray==INT_MIN ? -1 :n-longestSubarray;

    }
};
