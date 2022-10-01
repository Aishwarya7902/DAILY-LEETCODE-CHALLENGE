PROBLREM: https://leetcode.com/problems/decode-ways/
/*
FEEDBACK (KYU NI HUA)
at first mere se ye sawal ni hua


1.given a string of numbers....mujhe samjh ni aa raha ki uske corresponding possible number combination kaise generate karen
eg for 226 ...we can generate (2,2,6) ,(22,6) , (6,22)
2.for a given value how to get its corresponding key in a map
*/



/*OSERVATIONS
kind of backtracking question bol sakte ho
1.recursion lag raha yahan pe .....  now the question is ye kaise pata chala....
A.coz for every element in string we have "choice" ki usko len ki ni.....so jab bhi haamare pass choice ho then think about recursion
B.question me bola hai return the number of ways to decode it.....so jab bhi no of ways ki bat ho think about recursion 👀
*/

video: https://www.youtube.com/watch?v=UhxJq2eZFes
/*
recursion gives tle hence memoization
*/

class Solution {
private:
  int find(int i,string s,vector<int>&dp){
    if(s[i]=='0')return 0;
    if(i==s.size())return 1;
    if(dp[i]!=-1)return dp[i];
    int one=find(i+1,s,dp);
    int two=0;
    if(i<s.size()-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')){
      two+=find(i+2,s,dp);
    }
    return dp[i]=one+two;
  }
public:
    int numDecodings(string s) {
      vector<int>dp(s.size()+1,-1);
      return find(0,s,dp);  
    }
};

