PROBLEM:https://leetcode.com/problems/transpose-matrix/description/?envType=daily-question&envId=2023-12-10
VIDEO (MIK BHAIYA):

/*
  TC: O(m*n)
  SC: O(1)
*/

class Solution {
public:
    
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>result(n,vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               result[j][i]=matrix[i][j];
            }
        }
        return result;
    }
};


/*

  FOLLOW UP QUESTION .........WHAT IF THE MATRIX WAS A SQUARE MATRIX...........?

  */

for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
    swap(mat[i][j],mat[j],mat[i]);
  }
}


