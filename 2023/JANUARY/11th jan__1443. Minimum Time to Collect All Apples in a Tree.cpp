PROBLEM:https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/
VIDEO (MAZHAR BHAIYA):https://www.youtube.com/watch?v=qSBvKlUq0xo

/*
FOR EXPLANATION
BETTER SEE THE VIDEO....BAHOT ACHA QUESTION HAI YE
TC:O(V+E) //same as dfs
SC:o(v+e )
*/

class Solution {
private:
int dfs(unordered_map<int,vector<int>>&adj,int curr,int parent,vector<bool>& hasApple){
    int time=0;//initially time will be zero na
    //now travel its child
    for(auto &child:adj[curr]){
        if(parent==child)continue;
        int time_from_my_child=dfs(adj,child,curr,hasApple);
        if(time_from_my_child>0 || hasApple[child]){
            time+=time_from_my_child+2;
        }
    }
    return time;
}
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
      unordered_map<int,vector<int>>adj;//to store the graph
      for(auto &vec:edges){
          int u=vec[0];
          int v=vec[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      } 
      //now simply call dfs
      return dfs(adj,0,-1,hasApple); 
    }
};
