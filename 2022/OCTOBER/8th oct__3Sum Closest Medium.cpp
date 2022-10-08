PROBLEM:https://leetcode.com/problems/3sum-closest/
/*
EXACTLY SIMILAR TO 3SUM WITH LITTLE VARIATIONS : https://www.youtube.com/watch?v=onLoX6Nhvmg
TC: O(n^2)
sc:O(1)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int ans=INT_MIN;
      int curr=INT_MAX;
        int n=nums.size();
      for(int i=0;i<n-2;i++){
        int lo=i+1,hi=n-1,sum;
        
        while(lo<hi){
          sum=nums[i]+nums[lo]+nums[hi];
          if(sum==target)return sum;
          if(abs(sum-target)<curr){
            curr=abs(sum-target);
            ans=sum;
          }
          if(sum<target){
            lo++;
          }
          else 
            hi--;
        }
      }
      return ans;
    }
};
