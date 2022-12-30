PROBLEM: https://leetcode.com/problems/all-paths-from-source-to-target/description/
VIDEO(MAZHAR BHAIYA): https://www.youtube.com/watch?v=9qWMS8GLvdI

/*
for every node, we have two cases possible : 
1) That node will be in the result path
2) That node will not be in the result path

Since there are N node, TC : O(2^N)

*/

class Solution {
private:
void dfs(vector<vector<int>>& graph,int source,vector<int>ds,vector<vector<int>>&ans){
    ds.push_back(source);
    if(source==graph.size()-1){
        ans.push_back(ds);
    }
    else
    for(auto u:graph[source])
        dfs(graph,u,ds,ans);
    
    
    ds.pop_back();
}
public:

    vector<vector<int>> allPathsSourceTarget   (vector<vector<int>>& graph) {
        //source=0
        //target=n-1
       vector<vector<int>>ans;
       vector<int>ds;
       dfs(graph,0,ds,ans);
       return ans;
    }

};
