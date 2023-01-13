PROBLEM:https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
VIDEO: (BEST MAZHAR BHAIYA) https://www.youtube.com/watch?v=EA8dP63iVPk


class Solution {
private:
int result;
int dfs(unordered_map<int,vector<int>>&adj,int curr,int parent,string &s){
    int longest=0,secondLongest=0;
    for(auto &child:adj[curr]){
        if(child==parent)continue;
        int child_longest_length=dfs(adj,child,curr,s);
        if(s[child]==s[curr])continue;
        if(child_longest_length>secondLongest){
          secondLongest=child_longest_length;  
        }
        if(secondLongest>longest){
            swap(longest,secondLongest);
        }
    }
        int koi_ek_acha=max(longest,secondLongest)+1;
        int only_root_acha=1;
        int niche_hi_mil_gaya=1+longest+secondLongest;
        result=max({result,koi_ek_acha,only_root_acha,niche_hi_mil_gaya});
    return max(koi_ek_acha,only_root_acha);

}
public:
    int longestPath(vector<int>& parent, string s) {
       result=0;
       int n=parent.size();
       unordered_map<int,vector<int>>adj;
       for(int i=0;i<n;i++){
           int u=i;
           int v=parent[i];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       dfs(adj,0,-1,s);
       return result;
    }
};
