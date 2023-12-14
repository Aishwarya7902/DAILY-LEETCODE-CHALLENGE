PROBLEM:https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/?envType=daily-question&envId=2023-12-14
VIDEO :

/*
  BY SELF
  TC:O(M*N)
  SC:O(M+N)
*/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m,vector<int>(n,0));
        vector<int>rowOnes(m);
        vector<int>colOnes(n);
        vector<int>rowZeros(m);
        vector<int>colZeros(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    rowZeros[i]++;
                    colZeros[j]++;
                }
                else{
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[i][j]=rowOnes[i]+colOnes[j]-rowZeros[i]-colZeros[j];
            }
        }


    return result;

    }
};
