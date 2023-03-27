PROBLEM:https://leetcode.com/problems/minimum-path-sum/description/
VIDEO:https://www.youtube.com/watch?v=5viGdWz_tRY
BLOG:https://leetcode.com/problems/minimum-path-sum/solutions/3345863/image-explanation-recursion-dp-4-methods-c-java-python/?orderBy=most_votes&page=3

/*
METHOD 1
TC:O(m*n)
SC:O(m*n)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       //vector<int>v(n,0)
     vector<vector<int>>ans(grid);
       

       
       for(int i=1;i<m;i++){
          ans[i][0]+=ans[i-1][0];
       }
       for(int j=1;j<n;j++){
           ans[0][j]+=ans[0][j-1];
       }
       for(int i=1;i<m;i++){
           for(int j=1;j<n;j++){
               ans[i][j]+=min(ans[i-1][j],ans[i][j-1]);
           }
       }
       return ans[m-1][n-1];

    }
};
