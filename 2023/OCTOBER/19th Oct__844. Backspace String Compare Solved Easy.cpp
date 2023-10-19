PROBLEM:https://leetcode.com/problems/backspace-string-compare/description/?envType=daily-question&envId=2023-10-19
VIDEO:https://www.youtube.com/watch?v=u6K3j3n3vbA

/*
  METHOD 1
  TC:
  SC:O(M+N)
*/

class Solution {
public:
    string BackDelete(string &str){
        int n=str.size();
        int i=0;
        string temp="";
        while(i<n){
            if(str[i]!='#'){
                temp.push_back(str[i]);
            }
            else if(temp.size()>0)
             temp.pop_back();
            i++;
        }
        return temp;

    }
    bool backspaceCompare(string s, string t) {
        string temp1=BackDelete(s);
        string temp2=BackDelete(t);
        
        return temp1==temp2;
        
    }
};

/*
METHOD 2
TC:
SC:O(1)
  */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m=s.size();
        int n=t.size();
         
        int i=m-1;
        int j=n-1;

        int skip_s=0;
        int skip_t=0;
        while(i>=0 || j>=0){
        while(i>=0){
         if(s[i]=='#'){
          skip_s++;
          i--;
         }
         else if(skip_s>0){
          skip_s--;
          i--;
         }
         else
          break;
        }

        //similarly j

        while(j>=0){
         if(t[j]=='#'){
          skip_t++;
          j--;
         }
         else if(skip_t>0){
          skip_t--;
          j--;
         }
         else
          break;
        }

    char first=i<0 ? '$' : s[i];
    char second=j<0 ? '$' : t[j];
    if(first!=second)
     return false;
    i--;
    j--;


}
 return true;
    }

};
