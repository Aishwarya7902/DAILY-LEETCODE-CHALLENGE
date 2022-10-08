problem:https://leetcode.com/problems/3sum/
/*
brute force:
run three for loops and for every triplet if sum is zero store that triplet in  a set..make sure to sort vector v before inserting 
into set to get unique values.
tc:O(n^3 * log(m)) //n^3 coz we are running three for loops // log(m) for inserting m triplets in set
sc:O(m) // m is the  no of triplets
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>>ans;
      set<vector<int>>s;
      
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
              sort(v.begin(),v.end());
            }
            if(v.size()!=0)
              
              s.insert(v);
            
          }
        }
      } 
     for(auto it:s){
       ans.push_back(it);
     }
      return ans;
    }
};

/*
optimised
for explanation see striver bhaiya's video:https://www.youtube.com/watch?v=onLoX6Nhvmg&t=352s
tc: o(n*n) //see video for clarity
sc:O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<vector<int>>ans;
      for(int i=0;i<n-2;i++){
        if(i==0 || (i>0 && nums[i]!=nums[i-1] )){
          int lo=i+1,hi=n-1,sum=0-nums[i];
          while(lo<hi){
            if(nums[lo]+nums[hi]==sum){
             vector<int>temp;
             temp.push_back(nums[i]);
             temp.push_back(nums[lo]);
             temp.push_back(nums[hi]);
              ans.push_back(temp);
              while(lo<hi && nums[lo]==nums[lo+1])lo++;
              while(lo<hi && nums[hi]==nums[hi-1])hi--;
              lo++;
              hi--;
              
            }
            else if(nums[lo]+nums[hi]<sum)lo++;
            else hi--;
          
        }
      }
      }
        return ans;
    }
};
