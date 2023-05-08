PROBLEM:https://leetcode.com/problems/matrix-diagonal-sum/description/
VIDEO:

/*
tc:o(n^2)
sc:o(1)
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sumPre=0;
        int sumSec=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)sumPre+=mat[i][j];
                else if(i+j==n-1)sumSec+=mat[i][j];
            }
        }
        return sumPre+sumSec;
        
    }
};
