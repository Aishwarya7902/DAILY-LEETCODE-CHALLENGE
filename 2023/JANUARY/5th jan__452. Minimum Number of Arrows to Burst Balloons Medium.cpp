PROBLEM:https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
VIDEO:https://www.youtube.com/watch?v=zfcGwzfDNu0

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      int n=points.size();
      sort(begin(points),end(points));
      vector<int>prev=points[0];
      int cnt=1;
      for(int i=1;i<n;i++){
          int prevStartPoint=prev[0];
          int prevEndPoint=prev[1];
          int currStartPoint=points[i][0];
          int currEndPoint=points[i][1];
          if(currStartPoint>prevEndPoint){//no overlap
           cnt++;
           prev=points[i];
          }
          else{//pakka overlap
          //overlapping region nikalo
          prev[0]=max(prevStartPoint,currStartPoint);
          prev[1]=min(prevEndPoint,currEndPoint);

          }
      }
      return cnt;
    }
};
