PROBLEM:https://leetcode.com/problems/unique-paths/?envType=daily-question&envId=2023-09-03
VIDEO (MIK):https://www.youtube.com/watch?v=DaakAKiCkyc

/*
  RECURSION 
  TC: 2^N
  */

lass Solution {
public:
    int solve(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n)
         return 0;
        
        if(i==m-1 && j==n-1)
         return 1;
        int right=solve(i,j+1,m,n);
        int down=solve(i+1,j,m,n);

        return right+down;
    }
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};

/*
  MEMOIZATION
  TC:O(M*N)
  SC:O(M*N)

  */

  class Solution {
public:
    int t[101][101];
    int solve(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n)
         return 0;
        
        if(i==m-1 && j==n-1)
         return 1;
         if(t[i][j]!=-1)
          return t[i][j];
        int right=solve(i,j+1,m,n);
        int down=solve(i+1,j,m,n);

        return t[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n);
    }
};
