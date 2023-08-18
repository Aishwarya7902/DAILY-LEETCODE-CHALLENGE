PROBLEM:https://leetcode.com/problems/maximal-network-rank/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=R2sjm5jfwYY

/*
  METHOD 1:
  TC:O(v^2)

*/


class Solution {
public:
    bool isConnected(int city1,int city2,unordered_map<int,unordered_set<int>>&graph){
        if(graph[city1].find(city2)!=graph[city1].end())return true;

        return false;
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       
       unordered_map<int,unordered_set<int>>graph;
       int ans=INT_MIN;
       //making of graph;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            graph[u].insert(v);
            graph[v].insert(u);

        }
        //trying for each pair
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int network_City1=graph[i].size();
                int network_City2=graph[j].size();
                if(isConnected(i,j,graph))
                 ans=max(ans,(network_City1+network_City2)-1);

                else
                 ans=max(ans,(network_City1+network_City2));
            }
        }

        return ans;
    
    }
};
