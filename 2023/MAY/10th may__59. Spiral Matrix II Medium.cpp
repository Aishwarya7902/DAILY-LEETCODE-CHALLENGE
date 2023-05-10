PROBLEM:https://leetcode.com/problems/spiral-matrix-ii/description/
VIDEO:

/*
TC :o(n^2)
SC:o(1) //since we are not taking any extra space
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {};
        
        vector<vector<int>>ans(n,vector<int>(n,0));
        int top   = 0;
        int down  = n-1;
        int left  = 0;
        int right = n-1;
        int k=1;
        
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
                    ans[top][i]=k;
                    k++;
                }
                top++;
            }
            
            //top to down
            if(id == 1) {
                for(int i = top; i<=down; i++) {
                    ans[i][right]=k;
                    k++;
                }
                right--;
            }
            
            //right to left
            if(id == 2) {
                for(int i = right; i>=left; i--) {
                    ans[down][i]=k;
                    k++;
                }
                down--;
            }
            
            //down to top
            if(id == 3) {
                for(int i = down; i>=top; i--) {
                    ans[i][left]=k;
                    k++;
                }
                left++;
            }
            
            id = (id+1)%4;
        }
        return ans;
    }
};
