PROBLEM :https://leetcode.com/problems/sliding-window-maximum/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=29OnjVQ-fk4

/*
  SLIDING WINDOW
  TC: since we are processing each element once ......hence time complexity is linear..............i.e O(n)
  SC:
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        vector<int>ans;
        deque<int>dq;
        while(j<n){
            while(!dq.empty() && nums[j]>nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
            if(j-i+1<k)j++;
            else if(j-i+1==k){
                ans.push_back(nums[dq.front()]);
                if(nums[i]==nums[dq.front()]){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;

    }
};
