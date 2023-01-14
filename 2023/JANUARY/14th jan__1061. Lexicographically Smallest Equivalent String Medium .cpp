PROBLEM:https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
VIDEO:https://www.youtube.com/watch?v=DsAIuJmiT1c

/*
TC: O(M*DFS TC) i.e O(M*(v+e))
*/

class Solution {
private:
char dfsMinChar(unordered_map<char,vector<char>>&adj,char curr_ch,vector<int>&visited){
    visited[curr_ch-'a']=1;
    char minChar=curr_ch;
    for(char &v:adj[curr_ch]){
        if(visited[v-'a']==0){
            minChar=min(minChar,dfsMinChar(adj,v,visited));
        }
    }
    return minChar;
}
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string result;
       int n=s1.size();
       int m=baseStr.size();
       unordered_map<char,vector<char>>adj;
       for(int i=0;i<n;i++){
           int u=s1[i];
           int v=s2[i];
           adj[u].push_back(v);
           adj[v].push_back(u);

       } 
       for(int i=0;i<m;i++){
           vector<int>visited(26,0);
           char minChar=dfsMinChar(adj,baseStr[i],visited);
           result.push_back(minChar);

       }
       return result;
    }
};
