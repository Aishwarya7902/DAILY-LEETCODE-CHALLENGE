PROBLEM :https://leetcode.com/problems/is-subsequence/description/?envType=daily-question&envId=2023-09-22
VIDEO:(MIK BHAIYA) https://www.youtube.com/watch?v=r51_ZifUdvU

/*
  TC:O(M+N)
  SC:O(1)

  */

class Solution {
public:
    bool isSubsequence(string s, string t) {
       int m=s.size();
       int n=t.size();
       int i=0,j=0;
       while(i<m && j<n){
           if(s[i]==t[j])
            i++;
           j++;
       } 
       return i==m;
    }
};


/*
FOLLOW UP
TC:O(m*logn)
SC:O(m)
*/

lass Solution {
public:
    bool isSubsequence(string s, string t) {
       int m=s.size();
       int n=t.size();
       unordered_map<int,vector<int>>mp;
       //putting the index corresponding to every character of t
       for(int i=0;i<n;i++){
           mp[t[i]].push_back(i);
       }
       int prev=-1;

       for(int j=0;j<m;j++){
           char ch=s[j];
           //character not found in t
           if(mp.find(ch)==mp.end())return false;
           vector<int>curr=mp[ch];
           auto it=upper_bound(begin(curr),end(curr),prev);//o(logn)
           if(it==curr.end())return false;
           prev=*it;


       }
       return true;

    }
};
