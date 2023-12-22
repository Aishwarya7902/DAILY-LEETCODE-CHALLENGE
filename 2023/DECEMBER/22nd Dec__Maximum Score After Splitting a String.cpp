PROBLEM:https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
VIDEO(MIK BHIYA):

  
/*
  BRUTE FORCE (SOLVED BY OWN 😎)
  */

//TC:o(n*n) since constraints are low hence it will pass
//SC:o(1)
class Solution {
public:
// helper 1
    int rightOneCount(int start,int end,string &s){
        int count=0;
        for(int i=start;i<=end;i++){
            if(s[i]=='1')count++;
        }
        return count;
    }

// helper 2
    int leftZeroCount(int start,int end,string &s){
        int count=0;
        for(int i=start;i<=end;i++){
            if(s[i]=='0')count++;
        }
        return count;
    }
    int maxScore(string s) {
        int result=0;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            int zeroCount=leftZeroCount(0,i,s);
            int oneCount=rightOneCount(i+1,n-1,s);
            result=max(result,zeroCount+oneCount);
        }
        return result;
    }
};
