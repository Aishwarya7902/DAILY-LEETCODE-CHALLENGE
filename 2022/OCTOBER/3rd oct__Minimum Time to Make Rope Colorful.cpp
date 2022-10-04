PROBLEM:https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
VIDEO:https://www.youtube.com/watch?v=kBH9XnQQTSY

/*
my initial approach:
tc: O(n) since we are traversing the entire loop only once
sc: O(1)
*/
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0,j=0;
      int sum=0;
      int n=colors.size();
      while(i<n && j<n){
        int maxtime=INT_MIN;
        while(colors[i]==colors[j]){
          sum+=neededTime[j];
          maxtime=max(maxtime,neededTime[j]);
          j++;
        }
        sum-=maxtime;
        i=j;
      }
      return sum;
    }
};
