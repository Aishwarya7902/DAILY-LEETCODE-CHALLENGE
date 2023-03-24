PROBLEM:https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/
VIDEO(ARYAN MITTAL):https://www.youtube.com/watch?v=014NzNPJNbY
BLOG:https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/solutions/3334159/image-explanation-complete-intuition-dfs-c-java-python/?orderBy=most_votes&page=2

/*
DFS
TC: o(n) // n is no of nodes in tree
// o(n) coz...........as we go on to every node once
SC:  o(n) adjacency list for graph + o(n) visited array
*/

class Solution {
public:
    int dfs(vector<vector<int>>&graph,vector<bool>&vis,int src){
        auto change=0;
        vis[src]=1;
        for(auto v:graph[src]){
            if(!vis[abs(v)]){
                change+=dfs(graph,vis,abs(v))+ (v>0);// if v>0 then only we will increase change by 1....why????????
                //coz v>0 means there was an edge from 0-->node  ...but what we needed was an edge from node-->0 , hence we will have to revert back the edge.......IF U DONT UNDERSTAND ...PLZ WATCH ARYAN'S VIDEO
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        //make graph
        vector<vector<int>>graph(n);
        for(auto &it:connections){
            //if connections[i]=ai,bi ...........then there is a natural edge between ai-->bi
            graph[it[0]].push_back(it[1]);
            // we will make bidirectional....and for remembering which is virtual...we will make it -ve

            graph[it[1]].push_back(-it[0]);
        }
        //make a visited array
        vector<bool>vis(n,0);
        //call dfs
        return dfs(graph,vis,0);
    }
};
