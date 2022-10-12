PROBLEM:https://leetcode.com/problems/largest-perimeter-triangle/

/*
video:https://www.youtube.com/watch?v=gGsTZAK4F_I
tc:O(n)
sc:O(1)
pseudo code: sum of  two smaller sides should be greater than the largest side
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-3;i>=0;i--){
          if(nums[i]+nums[i+1]>nums[i+2]){
            return nums[i]+nums[i+1]+nums[i+2];
          }
        }
      return 0;
    }
};
