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

/*
optimisation

tc:o(n)
sc:o(1)

  */

class Solution {
public:
    int n;
    int longestSubarray(vector<int>& nums) {
       n=nums.size();
       int maxLen=0;
       int countZero=0;
       int i=0;
       for(int j=0;j<n;j++){
           if(nums[j]==0)countZero++;
           while(countZero>1){
               if(nums[i]==0)countZero--;
               i++;
           }
           maxLen=max(maxLen,j-i);
       } 
       return maxLen;
    }
};

/*
cleaner sliding window
*/

class Solution {
public:
    int n;
    int longestSubarray(vector<int>& nums) {
       n=nums.size();
       int maxLen=0;
       int last_zero_idx=-1;
       int i=0,j=0;
       while(j<n){
           if(nums[j]==0){
               i=last_zero_idx+1;
               last_zero_idx=j;
           }
           maxLen=max(maxLen,j-i);
           j++;
       }
       
       return maxLen;
    }
};
