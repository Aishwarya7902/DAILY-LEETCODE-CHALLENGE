PROBLEM:https://leetcode.com/problems/find-all-anagrams-in-a-string/

VIDEO:

/*
TC:
SC:
*/

class Solution {
private:
bool areEqual(vector<int> &freqS,vector<int> &freqP){
    for(int i=0;i<26;i++){
        if(freqS[i]!=freqP[i])return false;
    }
    return true;
}
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.size(),n=p.size();
        vector<int>ans;
        if(m<n)return ans;
        vector<int> freqS(26,0),freqP(26,0);
        for(char ch:p){
            freqP[ch-'a']++;
        }

        int begin=0,end=0;
        while(end<m){
         freqS[s[end]-'a']++;
         if(end-begin+1==n){
          
          if(areEqual(freqS,freqP))
          ans.push_back(begin);
          
         }
         
         if(end-begin+1<n) end++;
         
         while(end-begin+1>n){
             freqS[s[begin]-'a']--;
             end++;
             begin++;
         }
        }
        return ans;
    }
};
