PROBLEM :https://leetcode.com/problems/buddy-strings/description/

VIDEO:https://www.youtube.com/watch?v=LTrZCwuCoiE

/*
  TC:O(n)
  SC:
*/

class Solution {
public:
    bool checkFreq(string &s){
      int arr[26]={0};
      for(char &ch:s){
        arr[ch-'a']++;
        if(arr[ch-'a']>1)return true;
      }
      return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length())return false;

        if(s==goal){
          return checkFreq(s);
        }

        vector<int>index;
        for(int i=0;i<s.size();i++){
          if(s[i]!=goal[i])index.push_back(i);
        }
        if(index.size()!=2)return false;
        swap(s[index[0]],s[index[1]]);
        return s==goal;
    }
};
