PROBLEM:https://leetcode.com/problems/keys-and-rooms/description/
VIDEO:https://www.youtube.com/watch?v=qDHd9n_XGQ8
/*'SIMPLE DFS TRAVERSAL
Time complexity : 
Since we visit each room only once and we explore each edge only once.
So if number of rooms is = n
number of edges = m
Time complexity = O(m+n)
Space complexity = O(m+n)
*/

class Solution {
private:
void dfs(vector<vector<int>>& rooms,int source, vector<int>&vis){
    vis[source]=1;
    for(auto it:rooms[source]){
        if(!vis[it]){
            dfs(rooms,it,vis);
        }
    }
}
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
       
       //dfs calls
       vector<int>vis(n,0);
       vis[0]=1;
       dfs(rooms,0,vis);
       //check
       for(int i=0;i<n;i++){
          if(vis[i]==0)//one room found which is not visited
          return false; 
       }
       return true;
    }
};
