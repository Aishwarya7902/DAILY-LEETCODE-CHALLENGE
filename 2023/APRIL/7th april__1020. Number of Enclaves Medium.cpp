problem:https://leetcode.com/problems/number-of-enclaves/description/
blog:
video:https://www.youtube.com/watch?v=dYOm367BdbM

/*
self
pseudo code
simple hai
1.we cant move on the land of the edges..........so unka koi use ni..........hence mark them as water/sea
2.now simply run a dfs ......which will return no of land cells corresponding to that dfs call
3.add the returned value in final ans
*/

class Solution {
public:
    //dfs
    int  dfs(int i,int j,vector<vector<int>>& grid,int &count){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
         return 0;
        grid[i][j]=0;
        count++;
        dfs(i-1,j,grid,count);
        dfs(i+1,j,grid,count);
        dfs(i,j-1,grid,count);
        dfs(i,j+1,grid,count);
        return count;
    }
    //dfsEdge
    void dfsEdge(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
         return ;
        grid[i][j]=0;
        dfsEdge(i-1,j,grid);
        dfsEdge(i+1,j,grid);
        dfsEdge(i,j-1,grid);
        dfsEdge(i,j+1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       for(int i=0;i<m;i++){
           dfsEdge(i,0,grid);
           dfsEdge(i,n-1,grid);

       } 
       for(int j=0;j<n;j++){
           dfsEdge(0,j,grid);
           dfsEdge(m-1,j,grid);

       } 
       int cnt=0;
       for(int i=1;i<m-1;i++){
           for(int j=1;j<n-1;j++){
               if(grid[i][j]==1){
                   int count=0;
                   cnt+=dfs(i,j,grid,count);
               }
           }
       }
       return cnt;
    }
};


//method 2 : after making edge land as water , u can simply traverse the grid and count no of 1's.....as simple as thatclass Solution {
public:
    //dfsEdge
    void dfsEdge(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1)
         return ;
        grid[i][j]=0;
        dfsEdge(i-1,j,grid);
        dfsEdge(i+1,j,grid);
        dfsEdge(i,j-1,grid);
        dfsEdge(i,j+1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       for(int i=0;i<m;i++){
           dfsEdge(i,0,grid);
           dfsEdge(i,n-1,grid);

       } 
       for(int j=0;j<n;j++){
           dfsEdge(0,j,grid);
           dfsEdge(m-1,j,grid);

       } 

       int cnt=0;
       for(int i=1;i<m-1;i++){
           for(int j=1;j<n-1;j++){
               if(grid[i][j]==1){
                   
                   cnt++;
               }
           }
       }
       return cnt;
    }
};
