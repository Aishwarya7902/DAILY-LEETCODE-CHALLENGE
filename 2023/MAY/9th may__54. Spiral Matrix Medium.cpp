PROBLEM :https://leetcode.com/problems/spiral-matrix/description/
VIDEO:https://www.youtube.com/watch?v=73j2ipxR958
/*
TC:
SC:
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;
        
        int id = 0;
        //id
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top

        while(top <= down && left <= right) {
            //left to right
            if(id == 0) {
                for(int i = left; i<=right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            
            //top to down
            if(id == 1) {
                for(int i = top; i<=down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            
            //right to left
            if(id == 2) {
                for(int i = right; i>=left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            
            //down to top
            if(id == 3) {
                for(int i = down; i>=top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            
            id = (id+1)%4;
        }
        return result;
    }
};
