PROBLEM:https://leetcode.com/problems/sort-an-array/description/
VIDEO: 1.count sort(MAZHAR BHAIYA) :https://www.youtube.com/watch?v=PnyxRdn-N9U
       2.merge sort(striver bhaiya):

/*
METHOD 1 : 🙌 COUNTING SORT
TC:O(N+K) //here k is range from min to max element
SC:O(N)
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      //COUNTING SORT
      //1.store in map
      //2.find min,max
      //3.go from min to max
      //4.if present in map....insert it that much times

      unordered_map<int,int>mp;
      for(int &x:nums){
          mp[x]++;
      }  
      int minE=*min_element(begin(nums),end(nums));
      int maxE=*max_element(begin(nums),end(nums));
      int i=0;
      for(int num=minE;num<=maxE;num++){
          while(mp[num]>0){
              nums[i]=num;
              i++;
              mp[num]--;

          }
      }
      return nums;
    }
};
