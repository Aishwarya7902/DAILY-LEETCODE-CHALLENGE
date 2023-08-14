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


/*
 method 2:
 using priority queue
 TC:
 SC:
 */
 class Solution {
public:
    int n;
    int findKthLargest(vector<int>& nums, int k) {
        n=nums.size();
        priority_queue<int>pq;
        for(auto it:nums)
         pq.push(it);

        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};


