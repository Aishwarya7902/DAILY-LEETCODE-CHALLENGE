PROBLEM:https://leetcode.com/problems/number-of-closed-islands/description/

BEST BLOG:https://leetcode.com/problems/number-of-closed-islands/solutions/3384770/image-explanation-clean-generalized-code-c-java-python/?orderBy=most_votes

BEST VIDEO(ARYAN MITTAL) :https://www.youtube.com/watch?v=W29P4Z9ZQdQ 
//must watch

/*
method 1
tc:o(m*n)
sc:o(m*n) //coz of recursive stack space

*/

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=0)
         return ;
         grid[i][j]=1;
         dfs(i-1,j,grid);
         dfs(i+1,j,grid);
         dfs(i,j-1,grid);
         dfs(i,j+1,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
           
                dfs(i,0,grid);
                dfs(i,n-1,grid);
            
        }
        for(int j=0;j<n;j++){
                dfs(0,j,grid);
                dfs(m-1,j,grid);
        }
        int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};


/*
generalised code
*/

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=0)
         return ;
         grid[i][j]=1;
         int dx[4]={1,-1,0,0};
         int dy[4]={0,0,1,-1};
         for(int k=0;k<4;k++){
             int nx=i+dx[k];
             int ny=j+dy[k];
             dfs(nx,ny,grid);
         }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //making edge land as water
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i*j==0 || i==m-1 || j==n-1) && grid[i][j]==0)
                 dfs(i,j,grid);
            }
        }
        int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
