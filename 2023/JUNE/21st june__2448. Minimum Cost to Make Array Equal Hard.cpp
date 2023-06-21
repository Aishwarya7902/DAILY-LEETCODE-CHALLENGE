PROBLEM:https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/
VIDEO :https://www.youtube.com/watch?v=lGo6E8jiDB8

/*
  TC:O(nlogn)
  */

class Solution {
public:
typedef long long ll;
    ll findCost(vector<int>& nums, vector<int>& cost,int target){
        ll result=0;
        for(int i=0;i<nums.size();i++){
            result+=(ll) abs(nums[i]-target)*cost[i];
        }
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
       ll answer=INT_MAX;
       int left=*min_element(begin(nums),end(nums)) ;
       int right=*max_element(begin(nums),end(nums));
       while(left<=right){
           int mid=left+(right-left)/2;
           ll cost1=findCost(nums,cost,mid);
           ll cost2=findCost(nums,cost,mid+1);
           answer=min(cost1,cost2);
           if(cost2>cost1){
               right=mid-1;

          }
          else{
              left=mid+1;
          }

       }
       return answer== INT_MAX ? 0 : answer;
    }
};
