PROBLEM :https://leetcode.com/problems/path-with-maximum-probability/description/

VIDEO:https://www.youtube.com/watch?v=zTM9k6jqpXI

//tc:O(ElogV)
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>>adj;
        vector<double>result(n,0);

        //STEP 1:make graph

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
           double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        //take a priority queue
        priority_queue<pair<double,int>>pq; //max heap

        result[start]=1; //probablity to reach from start to start is 100%

        pq.push({1.0,start});
        while(!pq.empty()){
            int currNode=pq.top().second;
            double currProb=pq.top().first;
            pq.pop();

            for(auto &temp:adj[currNode]){
                int adjNode=temp.first;
                double adjProb=temp.second;
                if(result[adjNode]<currProb*adjProb){
                    result[adjNode]=currProb*adjProb;
                    pq.push({result[adjNode],adjNode});
                }
            }
        }
     return result[end];
    }
};
