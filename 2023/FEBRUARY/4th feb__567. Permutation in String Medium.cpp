PROBLEM:https://leetcode.com/problems/permutation-in-string/description/
/*
TC: O(M+N)
SC:O(1) ...SINCE WE USED ONLY VECTOR OF A CONSTANT SIZE
*/

class Solution {
private:
bool areEqual(vector<int> &freqs1,vector<int> &freqs2){
    for(int i=0;i<26;i++){
        if(freqs1[i]!=freqs2[i])return false;
    }
    return true;
}
public:
    bool checkInclusion(string s1, string s2) {
       int n=s1.size(),m=s2.size();
       if(m<n)return false;
       vector<int> freqs1(26,0),freqs2(26,0); 
       for(char ch:s1)
        freqs1[ch-'a']++;
       int begin=0,end=0;
       while(end<m){
           freqs2[s2[end]-'a']++;
           
           if(end-begin+1==n){
               if(areEqual(freqs1,freqs2))return true;
           }
           if(end-begin+1<n)end++;
           
           else{
               freqs2[s2[begin]-'a']--;
               end++;
               begin++;
           }
       }
       return false;
    }
};
