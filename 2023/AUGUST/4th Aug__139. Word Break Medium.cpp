PROBLEM :https://leetcode.com/problems/word-break/description/
VIDEO(MAZHAR BHAIYA) :https://www.youtube.com/watch?v=oBUpyPZ08zU

/*
  RECURSION
  TC: N*(2^N)
  SC:
*/

class Solution {
public:
    unordered_set<string>st;
    int n;

    //helper
    bool solve(int indx,string &s){
        if(indx>=n){
            return true;
        }

        if(st.find(s)!=st.end())
         return true;

        for(int l=1;l<=n;l++){
            string temp=s.substr(indx,l);
            if(st.find(temp)!=st.end() && solve(indx+l,s)){
                return true;

            }
        }

        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(string &word:wordDict){
            st.insert(word);
        }

        return solve(0,s);

    }
};


/*

RECUSRION + MEMO
  TC:
  SC:
*/

class Solution {
public:
    unordered_set<string>st;
    int n;
    int t[301];

    //helper
    bool solve(int indx,string &s){
        if(indx>=n){
            return true;
        }
        if(t[indx]!=-1){
            return t[indx];
        }

        if(st.find(s)!=st.end())
         return t[indx]=true;

        for(int l=1;l<=n;l++){
            string temp=s.substr(indx,l);
            if(st.find(temp)!=st.end() && solve(indx+l,s)){
                return t[indx]=true;

            }
        }

        return t[indx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();

        for(string &word:wordDict){
            st.insert(word);
        }
        memset(t,-1,sizeof(t));

        return solve(0,s);

    }
};
