PROBLEM:https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2023-11-13
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=nEDXPkGsjXo

/*
  SOLVED ON OWN
  TC:o(nlogn)
  SC:o(n)

*/

class Solution {
public:
   bool isVowel(char x){
       if(x=='a' || x=='A' ||x=='e'||x=='E' || x=='i' ||x=='I' ||x=='o' ||x=='O' ||x=='u' ||x=='U')return true;

       return false;
   }
    string sortVowels(string s) {
        string curr;
        string t;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!isVowel(s[i])){
                t+=s[i];
            }
            else{
                t+='.';
                curr+=s[i];
            }
        }

        sort(begin(curr),end(curr));
        int j=0;
        for(int i=0;i<t.size();i++){
            if(t[i]=='.'){
                t[i]=curr[j];
                j++;
            }
        }
     return t;
    }
};
