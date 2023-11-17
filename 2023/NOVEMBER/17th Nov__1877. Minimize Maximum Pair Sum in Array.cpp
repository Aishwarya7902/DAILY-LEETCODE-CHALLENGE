PROBLEM:https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2023-11-17
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=1L9C3a38fHU&t=28s

/*
  TC:O(nlogn)
  SC:O(1)

  */

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int i=0,j=n-1;
        int sum;
        int res=0;
        while(i<j){
            sum=nums[i]+nums[j];
            res=max(res,sum);
            i++;
            j--;
        }
        return res;
    }
};
