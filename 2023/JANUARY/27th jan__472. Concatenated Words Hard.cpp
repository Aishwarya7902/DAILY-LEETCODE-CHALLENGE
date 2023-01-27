PROBLEM:https://leetcode.com/problems/concatenated-words/description/
VIDEO:https://www.youtube.com/watch?v=zZsnMAgM6Q0

/*
O(n*l^4)
*/

class Solution {
private:
unordered_set<string> st;
bool isConcat(string s){
    for(int i=1;i<s.size();i++){
        string suffix=s.substr(i);
        string prefix=s.substr(0,i);
        if(st.count(prefix)>0 && (st.count(suffix)>0 || isConcat(suffix)))return true;
    }
    return false;
}
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        st.clear();
        if(words.size()==0)return ans;
        
        for(auto s:words){
            st.insert(s);
        }
        for(auto s:words){
            if(isConcat(s))
             ans.push_back(s);
        }
        return ans;

    }
};
