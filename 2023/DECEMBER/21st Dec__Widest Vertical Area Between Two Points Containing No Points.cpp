PROBLEM :https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=QZuxYdVNoIU

/*
  TC:O(nlogn) //sorting
  SC:O(1)
  */

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size();
        sort(begin(points),end(points));
        int result=0;
        for(int i=1;i<n;i++){
            int width=points[i][0]-points[i-1][0];
            result=max(result,width);
        }

        return result;
    }
};




