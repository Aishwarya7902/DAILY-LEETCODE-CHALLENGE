problem:https://leetcode.com/problems/3sum/
/*
brute force:
run three for loops and for every triplet if sum is zero store that triplet in  a set
tc:O(n^3 * log(m)) //n^3 coz we are running three for loops // log(m) for inserting m triplets in set
sc:O(m) // m is the  no of triplets
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>>ans;
      vector<int>v;
      int n=nums.size();
      for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
          for(int k=j+1;k<n;k++){
            v.clear();
            if(nums[i]+nums[j]+nums[k]==0){
              
              v.push_back(nums[i]);
              v.push_back(nums[j]);
              v.push_back(nums[k]);
            }
            if(v.size()!=0)
              ans.insert(v);
            
          }
        }
      } 
     
      return ans;
    }
};
