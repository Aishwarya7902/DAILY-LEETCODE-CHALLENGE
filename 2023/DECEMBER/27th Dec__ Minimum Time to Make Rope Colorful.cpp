PROBLEM:https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2023-12-27
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=_xNrzKfORNA&t=1113s

/*
  TC:O(n)
  SC:O(1)
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

         int n=colors.size();

         int time=0;
         int prevMax=0;
         for(int i=0;i<n;i++){
             if(i>0 && colors[i]!=colors[i-1]){
                 prevMax=0;
             }
             int curr=neededTime[i];
             time+=min(curr,prevMax);
             prevMax=max(prevMax,curr);
         }


         return time;
    }
};
