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


/*
  TC: O(N) //2 pass solution
  SC: O(1)
  // totalOnes nikal lo
  // har index tak zero  ka and one ka  count nikalte lo...that will be left me kitne zero hain and kitne one hain
  // agr left side me one ka count pata hai...to total-left kar ke right me one ka count nikal jayega
  */

//TC:o(n*n) since constraints are low hence it will pass
//SC:o(1)
class Solution {
public:
    int maxScore(string s) {
        int result=0;
        int n=s.size();
        int totalOne=0;
        for(char &ch:s){
            if(ch=='1')totalOne++;
        }
        int zero=0;
        int one=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0')zero++;
            else if(s[i]=='1')one++;
            int currRes=zero+(totalOne-one);
            result=max(result,currRes);
        }
        return result;
    }
};

//Approach-3 (1 Pass - Use equation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int result = INT_MIN;

        
        int zeros = 0;
        int ones  = 0;
        
        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            result = max(result, zeros - ones);
        }
        
        if(s[n-1] == '1') {
            ones++;
        }
        
        return result+ones;
    }
};


