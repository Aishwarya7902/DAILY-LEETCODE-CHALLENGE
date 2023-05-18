PROBLEM:https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
VIDEO:https://www.youtube.com/watch?v=7wGJ1nevpnc

/*
SOLVED BY SEEING HINT
TC:O(N)
SC:O(N)
Hint
(1/3)
A node that does not have any incoming edge can only be reached by itself.

(2/3)
Any other node with incoming edges can be reached from some other node.

(3/3)
We only have to count the number of nodes with zero incoming edges.

*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            indegree[v]++;
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)ans.push_back(i);
        }
        return ans;
        
    }
};
