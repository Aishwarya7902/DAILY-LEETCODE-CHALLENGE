PROBLEM:https://leetcode.com/problems/pascals-triangle-ii/description/?envType=daily-question&envId=2023-10-16
PROBLEM:https://www.youtube.com/watch?v=ocGDVKYJKVo&t=273s

/*
  METHOD 1
  TC:
  SC:
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>result(rowIndex+1);
        for(int i=0;i<rowIndex+1;i++){
            result[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                result[i][j]= result[i-1][j]+ result[i-1][j-1];
            }
        }
        return result[rowIndex];
    }
};
