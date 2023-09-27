PROBLEM:https://leetcode.com/problems/remove-duplicate-letters/description/?envType=daily-question&envId=2023-09-26
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=rU5p0MRm5zU

/*
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        string result;
        vector<int>lastIndex(26);
        vector<bool>taken(26,false);
        for(int i=0;i<n;i++){
            char ch=s[i];
            lastIndex[ch-'a']=i;
        }

        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            if(taken[idx]==true)continue;
            while(result.size()>0 && result.back()>ch && lastIndex[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[idx]=true;
        }
        return result;

    }
};
