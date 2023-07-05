PROBLEM:https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

VIDEO:https://www.youtube.com/watch?v=SQ8tY9nxeZU

/*
  BRUTE FORCE: 
TC:O(N^2)
SC:O(1)

  */

class Solution {
public:
    int n;
    int findMax(vector<int>& nums,int skip_indx){
        int currLen=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
            if(i==skip_indx)continue;
            if(nums[i]==1){
                currLen++;
                maxLen=max(maxLen,currLen);
            }
            else{
                currLen=0;
            }
        }
        return maxLen;
    }
    int longestSubarray(vector<int>& nums) {
        n=nums.size();
        int countZero=0;
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                countZero++;
                result=max(result,findMax(nums,i));
            }
        }
        if(countZero==0)return n-1;

        return result;
        
    }
};
