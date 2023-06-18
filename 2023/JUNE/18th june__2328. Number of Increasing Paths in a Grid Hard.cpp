PROBLEM:https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
VIDEO:https://www.youtube.com/watch?v=s-dQjzykhVA

class Solution {
public:
    int m,n;
    vector<vector<int>>direction={
          {-1,0},
    {0,-1},     {0,1},
          {1,0}
    };
    bool isSafe(int i,int j){
        return (i<m && i>=0 && j<n && j>=0);
    }
    int t[1001][1001];
    long long MOD=1e9+7;
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(t[i][j]!=-1)return t[i][j];
        int answer=1;//khud me increasing path to hai hi
        for(auto &dir:direction){
            int i_=i+dir[0];
            int j_=j+dir[1];
            if(isSafe(i_,j_) && grid[i_][j_]<grid[i][j]){
                answer= (answer+dfs(grid,i_,j_))%MOD;
            }
        }
        return t[i][j]=answer;
    }
    int countPaths(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        m=grid.size();
        n=grid[0].size();
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result= (result+dfs(grid,i,j))%MOD;
            }
        }
        return result;
    }
};
