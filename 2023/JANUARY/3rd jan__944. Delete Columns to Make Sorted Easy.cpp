PROBLEM:https://leetcode.com/problems/delete-columns-to-make-sorted/description/
VIDEO:

/*
MY INTUITION
TC: O(N*K) , where n is size of strs vector and k is size 
SC:
*/
class Solution {
private:
bool IsLexico(vector<string>& strs,int col){//this function return true if all the characters of that column are sorted /lexicographically arranged
    for(int i=1;i<strs.size();i++){
        if(strs[i-1][col]>strs[i][col])return false;
    }
    return true;
}
public:
    int minDeletionSize(vector<string>& strs) {
     int colToDelete=0;
     for(int i=0;i<strs[0].size();i++){
         if(!IsLexico(strs,i)) //if that column is not in lexicographic order then we will have to delete it ,hence increase colToDelete by 1
          colToDelete++;
     }
     return colToDelete;  
    }
};
