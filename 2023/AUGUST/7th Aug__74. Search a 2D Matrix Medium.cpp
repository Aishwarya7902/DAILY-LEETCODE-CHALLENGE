PROBLEM:https://leetcode.com/problems/search-a-2d-matrix/description/
VIDEO:

/*
  brute force
just do a simple two for loop
TC :o(m x n)

  */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target)return true;
            }
        }
        return false;
        
    }
};

/*
approach 2

  TC: o(m x n)
since in worst case u will have to look in each cell of the matrix

  */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(matrix[i][j]>target)
             j--;
            else if(matrix[i][j]<target)
             i++;
            else
             return true;
        }
        return false;
        
    }
};
