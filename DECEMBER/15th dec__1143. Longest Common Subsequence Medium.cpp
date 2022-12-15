PROBLEM:https://leetcode.com/problems/longest-common-subsequence/description/
VIDEO (STRIVER BHAIYA) : https://www.youtube.com/watch?v=NPZn9jBrX8U

/*
RECURSION
TC:exponential
SC:exponential
*/

class Solution {
private:
int helpLcs(string text1,int indx1,string text2,int indx2){
    if(indx1<0 || indx2<0)return 0; //negative index implies end of string
    //if both indexes matches
    if(text1[indx1]==text2[indx2]){
        return 1+helpLcs(text1,indx1-1,text2,indx2-1);
    }
    //no match....then try out both possibilities
    return max(helpLcs(text1,indx1,text2,indx2-1),helpLcs(text1,indx1-1,  text2,indx2));

}
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();//size of string1
      int m=text2.size();//size of string2
      return helpLcs(text1,n-1,text2,m-1);  
    }
};
