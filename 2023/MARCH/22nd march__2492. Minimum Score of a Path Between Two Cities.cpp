PROBLEM:https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
BLOG:https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/solutions/3326775/image-explanation-both-bfs-dfs-approaches-c-java-python-union-find-is-overrated/?orderBy=most_votes
VIDEO:

/*
METHOD 1
BFS
TC:O(V+E)
SC:O(V+E)
*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
      //to store ans
      int ans=INT_MAX;
      //make graph
      vector<vector<pair<int,int>>>graph(n+1);
      for(auto edge:roads){
          graph[edge[0]].push_back({edge[1],edge[2]});
           graph[edge[1]].push_back({edge[0],edge[2]});
      } 
      //bfs
      vector<bool>vis(n+1,0);
      queue<int>q;
      q.push(1);
      vis[1]=1;
      while(!q.empty()){
          auto node=q.front();
          q.pop();
          for(auto &[v,dis]:graph[node]){
              ans=min(ans,dis);
              if(!vis[v]){
                  vis[v]=1;
                  q.push(v);
              }
          }
      }
      return ans; 
    }
};
