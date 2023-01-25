PROBLEM:https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/
VIDEO:

/*
tc:o(n)
sc:o(n)

pseudo code:
1.dist1 will store distance of each node from node 1
2.dist2 will store distance of each node from node 2
3.Run the depth-first search (DFS) algorithm from node1 and update the dist1 and visited1 arrays accordingly.
4.Run the DFS algorithm from node2 and update the dist2 and visited2 arrays accordingly.
5.Iterate through all nodes currNode in the graph.
6.For each node, check if it has been visited by both DFS calls, and if its maximum distance from 
node1 and node2 is less than the current value of minDist update the value of minDist and ans to the
current node's distance and index, respectively
7.Return ans as the result.

*/class Solution {
private:
void Helpdfs(int node,vector<int>& edges,vector<int>& distance,vector<bool>& visited){
    visited[node]=true;
    int neighbour=edges[node];
    if(neighbour!=-1 && visited[neighbour]==false){
        distance[neighbour]=distance[node]+1;
        Helpdfs(neighbour,edges,distance,visited);
    }
}
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
     int n=edges.size();
     int ans=-1;
     int minDis=INT_MAX;
     vector<int> dist1(n,0),dist2(n,0);
     vector<bool> vis1(n,false),vis2(n,false);
     Helpdfs(node1,edges,dist1,vis1);
     Helpdfs(node2,edges,dist2,vis2);
     for(int curr=0;curr<n;curr++){
         if(vis1[curr] && vis2[curr] && minDis>max(dist1[curr],dist2[curr])){
            minDis=max(dist1[curr],dist2[curr]);
            ans=curr;
         }
     } 
     return ans;  
    }
};
