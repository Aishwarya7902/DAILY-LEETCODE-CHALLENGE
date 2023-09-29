PROBLEM:https://leetcode.com/problems/monotonic-array/description/?envType=daily-question&envId=2023-09-29
VIDEO:https://www.youtube.com/watch?v=LfYSyPP6YOA

/*
  METHOD 1 
  SOLVED ON MY OWN
*/

//tc:o(n)
//sc:o(1)
class Solution {
public:
    bool isIncreasing(vector<int>& nums){
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])return false;
        }

        return true;
    }

    bool isDecreasing(vector<int>& nums){
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])return false;
        }

        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        bool result=false;
        result=isIncreasing(nums);
        if(result)return result;
        result=isDecreasing(nums);
        return result;
    }
};


/*

METHOD 2:
TC:O(N)
SC:O(1)
  */

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      int n=nums.size();
      bool Increasing=false;
      bool Decreasing=false;
      for(int i=0;i<n-1;i++){
          if(nums[i]<nums[i+1]){
               Increasing=true;
          }
          if(nums[i]>nums[i+1]){
               Decreasing=true;
          }
      }
      //if array is both increasing as well as decreasing ...simply return false
      if(Increasing && Decreasing)return false;

      return true;

    }
};
