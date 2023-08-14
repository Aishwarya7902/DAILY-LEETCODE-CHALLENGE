PROBLEM:https://leetcode.com/problems/kth-largest-element-in-an-array/description/
VIDEO(MIK BHAIYA):


/*
METHOD 1
BRUTE FORCE
simply sort the array.....return the kth largest element
TC: nlogn ....for sorting
SC:O(1)
  */

class Solution {
public:
    int n;
    int findKthLargest(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-k];

    }
};


