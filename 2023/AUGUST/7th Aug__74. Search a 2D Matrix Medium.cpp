PROBLEM:https://leetcode.com/problems/search-a-2d-matrix/description/
VIDEO:https://www.youtube.com/watch?v=NYk3IuJinuc

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

/*METHOD 3

  USING BINARY SEARCH
  O(log(m * n))
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        //since the whole matrix is sorted ...then ...whole 2D matrix ko khol do .....it will become a 1D sorted array...then do a binary search
        int start=0;
        int end=m*n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int row=mid/n;
            int col=mid%n;

            if(matrix[row][col]>target){
                end=mid-1;
            }
            else if(matrix[row][col]<target){
                start=mid+1;
            }
            else
             return true;
        }
        return false;
        
    }
};
