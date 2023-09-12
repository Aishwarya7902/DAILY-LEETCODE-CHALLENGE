PROBLEM:https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
VIDEO:https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={0};
        for(char &ch:s){
            freq[ch-'a']++;

        }
        int result=0;
        unordered_set<int>st;
        for(int i=0;i<26;i++){
            while(freq[i]>0 && st.find(freq[i])!=st.end()){
                freq[i]-=1;
                result++;
            }
            st.insert(freq[i]);
        }
        return result;
    }
};
