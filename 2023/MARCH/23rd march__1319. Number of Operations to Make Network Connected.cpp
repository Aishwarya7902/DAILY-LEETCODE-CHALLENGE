PROBLEM:https://leetcode.com/problems/number-of-operations-to-make-network-connected/
BLOG:https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/3330446/image-explanation-easiest-dfs-c-java-python/?orderBy=most_votes&page=2
VIDEO:https://www.youtube.com/watch?v=VG_TjZ9wWfE

/*
DFS
TC:O(connections) //going all over the connection/wires
SC:O(N) //storing n nodes in a graph
*/

class Solution {
public:
    void dfs(int src,vector<vector<int>>&graph,vector<bool>&vis){
        vis[src]=1;
        for(auto u:graph[src]){
            if(!vis[u]){
                dfs(u,graph,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      if(connections.size()<n-1)return -1;
      vector<bool>vis(n,0);
      vector<vector<int>>graph(n);
      //making of a graph
      for(auto it:connections){
          graph[it[0]].push_back(it[1]);
          graph[it[1]].push_back(it[0]);
      }
      //calling dfs
      int cnt=0;
      for(int i=0;i<n;i++){
          if(vis[i]==0){
               dfs(0,graph,vis); 
               cnt++;
          }

      }
     
      
      return cnt-1;
    }
};
