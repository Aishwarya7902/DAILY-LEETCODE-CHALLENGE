PROBLEM:https://leetcode.com/problems/valid-sudoku/

/*
MY APPROACH
1.using the isValid function of sudoko solver we can easily solve this question
2. so the approach is like

pseudo code
1.traverse the board and if u find other than blank ...then put '.' and store its value in some temp character there ....and then check for isValid...that
means  if this character is already present in the row,col or same box...if yes return false from there
otherwise we backtrack and put the temp character over there.
2.at last if we dont return false from anywhere ...return true.
*/

class Solution {
private:
  bool isValid(vector<vector<char>>& board,int row,int col,char c){
    for(int i=0;i<9;i++){
      if(board[i][col]==c)
        return false;
      if(board[row][i]==c)
        return false;
      if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
        return false;
    }
    return true;
  }
  
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<board.size();i++){
         for(int j=0;j<board[0].size();j++){
           if(board[i][j]!='.'){
             char c=board[i][j];
             board[i][j]='.';
             if(isValid(board,i,j,c)==false)return false;
             else
               board[i][j]=c;
           }
         }
       }
      return true;
    }
};
