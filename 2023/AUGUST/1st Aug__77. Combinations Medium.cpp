PROBLEM:https://leetcode.com/problems/combinations/description/
VIDEO:https://www.youtube.com/watch?v=QQ9Tn2i269I

/*
  METHOD 1
  TC: nCk
*/

class Solution {
public:
    vector<vector<int>> result;

    //helper function

    void solve(int start,int n,int k,vector<int>&temp){
        if(k==0){
            result.push_back(temp);
            return;
        }
        if(start>n)
         return;

        //start ko lo aur explore karo

        temp.push_back(start);
        solve(start+1,n,k-1,temp);

        //element_not_taken ko explore karo

        //bactrack ........then explore

        temp.pop_back();
        solve(start+1,n,k,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(1,n,k,temp);
        return result;    
    }
}; 
