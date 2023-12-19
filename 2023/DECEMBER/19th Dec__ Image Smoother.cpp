PROBLEM:https://leetcode.com/problems/image-smoother/description/?envType=daily-question&envId=2023-12-19

VIDEO:

/*
  BRUTE FORCE:
  TC:O(M*N*9)
  SC:O(M*N)
*/

class Solution {
public:
   vector<vector<int>> direction
    {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>result(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum_neighbour=0;
                int count_neighbour=0;
                for(auto &it:direction){
                    int new_i= i+it[0];
                    int new_j= j+it[1];
                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n){
                        sum_neighbour+=img[new_i][new_j];
                        count_neighbour++;
                    }
                }
                result[i][j]=sum_neighbour/count_neighbour;
            }
        }

    return result;
    }
};
