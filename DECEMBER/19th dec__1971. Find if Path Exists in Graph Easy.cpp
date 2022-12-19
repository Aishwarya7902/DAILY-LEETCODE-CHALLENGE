PROBLEM:https://leetcode.com/problems/find-if-path-exists-in-graph/description/

/*
USING DFS
*/

class Solution {
private:
void dfs(vector<int>adj[],vector<int>&vis,int source){
    vis[source]=1;
    for(auto u:adj[source]){
      if(!vis[u]){
          dfs(adj,vis,u);
      }
    }
}
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)return true;
        
        vector<int>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        dfs(adj,vis,source);
       return vis[destination] ;
    }
};
