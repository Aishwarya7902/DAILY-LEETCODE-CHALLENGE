PROBLEM:https://leetcode.com/problems/search-in-rotated-sorted-array/description/
VIDEO:

/*
  BRUTE FORCE
  TC:O(N)
  SC:O(1)

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target)return i;
        }
        return -1;
        
    }
};
