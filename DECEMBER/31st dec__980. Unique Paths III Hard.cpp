PROBLEM: https://leetcode.com/problems/unique-paths-iii/description/
VIDEO(MAZHAR BHAIYA.....BEST EXPLANATION EVER):https://www.youtube.com/watch?v=eagGLroZXMk

/*
TC: 3^(M*N)
SIMPLE BACKTRACKING
*/

class Solution {
private:
int m,n;
int result,nonObstacle;
vector<vector<int>>direction{{1,0},{-1,0},{0,1},{0,-1}};

void backTrack(vector<vector<int>>& grid,int count,int i,int j){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1)return;
    if(grid[i][j]==2){
        if(count==nonObstacle)
         result++;
         return;
        
    }
    grid[i][j]=-1;
    for(auto dir:direction){
        int new_i=dir[0]+i;
        int new_j=dir[1]+j;
        backTrack(grid,count+1,new_i,new_j);
    }
    //backtrack
    grid[i][j]=0;
}
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
       m=grid.size();
       n=grid[0].size();
      int count=0;
       result=0;
       //story
       //count nonObstacle
       //find startX ,startY
       //call backTrack
       //return result
       int start_x=0,start_y=0;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==0)
                nonObstacle++;
               if(grid[i][j]==1){
                   start_x=i;
                   start_y=j;
               }
           }
       }
       nonObstacle+=1;
       backTrack(grid,count,start_x,start_y);
       return result; 
    }
};

