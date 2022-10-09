PROBLEM: https://leetcode.com/problems/two-sum/

/*
initial approach
pseudpo code:
1.run two for loops 
2.if a[i]+a[j]==target push i,j in a vector and return 

tc:O(n^2) //since we are using two for loops
sc:O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
          for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
              ans.push_back(i);
              ans.push_back(j);
              return ans;
            }
          }
        }
      return ans;
    }
};
