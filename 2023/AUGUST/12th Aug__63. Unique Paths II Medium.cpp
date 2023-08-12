PROBLEM:https://leetcode.com/problems/unique-paths-ii/
VIDEO(MIK BHAIYA) :https://www.youtube.com/watch?v=JC1fSPdJjMc

/*
  RECURSION

  TC: // since for every cell we have two options first is to go to right and the next is to go to the down ...and overall there are m*n cells.......
hence the time complexity will be o(2^(m*n))

SC: auxiliary stack space
*/


class Solution {
public:
    int m ,n;  
    // helper
    int solve(int i,int j,vector<vector<int>>& obstacleGrid){

        //base case 1
        if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }

        //base case 2
        if(i==m-1 && j==n-1){
            return 1;
        }

        // hypothesis

        int right=solve(i,j+1,obstacleGrid);
        int down=solve(i+1,j,obstacleGrid);

        //induction step
        return right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        return solve(0,0,obstacleGrid);
    }
};



/*
memoization
TC: O(M*N)
SC:O(M*N)
*/

class Solution {
public:
    int m ,n; 
    int t[101][101]; 
    // helper
    int solve(int i,int j,vector<vector<int>>& obstacleGrid){

        //base case 1
        if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        //base case 2
        if(i==m-1 && j==n-1){
            return 1;
        }

        // hypothesis

        int right=solve(i,j+1,obstacleGrid);
        int down=solve(i+1,j,obstacleGrid);

        //induction step
        return t[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,obstacleGrid);
    }
};
