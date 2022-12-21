PROBLEM:https://leetcode.com/problems/possible-bipartition/description/
VIDEO:https://www.youtube.com/watch?v=0ACfAqs8mm0
BLOG:https://leetcode.com/problems/possible-bipartition/solutions/2834180/possible-bipartition/?orderBy=most_votes

/*
INTUITION 
SIMPLE BIPARTITE GRAPH
THE WAY WE USED TO COLOR THE GRAPH USING TWO COLORS ,IN THE SAME WAY WE WILL TRY TO DIVIDE INTO TWO TEAMS
TC:O(V+E)
SC:O(V+E)
MISTAKE
//if 1 hates 2 then 2 also hates 1 na ,HENCE
           adj[person].push_back(notLike);
           adj[notLike].push_back(person);
           
           NOT JUST
           adj[person].push_back(notLike);
*/

class Solution {
private:
bool bfs(int source,int n,vector<int>adj[],int team[]){
    queue<int>q;
    q.push(source);
    team[source]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(team[it]==-1)
            {
                team[it]=1-team[node];
                q.push(it);
            }
            else if(team[it]==team[node])return false;
        }
    }
    return true;
}
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       vector<int>adj[n+1];
       for(int i=0;i<dislikes.size();i++){
           int person=dislikes[i][0];
           int notLike=dislikes[i][1];
           //if 1 hates 2 then 2 also hates 1 na
           adj[person].push_back(notLike);
           adj[notLike].push_back(person);
       } 
       int team[n+1];
       for(int i=0;i<=n;i++){
           team[i]=-1;
       }
       //call bfs;
       for(int i=1;i<=n;i++){
           if(team[i]==-1){
               if(bfs(i,n,adj,team)==false)return false;
           }
       }
       return true;
    }
};
