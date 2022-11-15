PROBLEM: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
video: (striver bhaiya) : https://www.youtube.com/watch?v=OwMNX8SPavM
dsu video: (striver bhaiya) :https://www.youtube.com/watch?v=aBxjDBC4M1U

class Solution {
public:
  class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
  
  //parent find
    int FindUParent(int node){
        if(node==parent[node])return node ;
      return  parent[node]=FindUParent(parent[node]);
    }
  
  //union
    
    void FindUnionByRank(int u,int v){
        int ulP_u=FindUParent(u);
        int ulP_v=FindUParent(v);
        if(ulP_v==ulP_u)return;
        if(rank[ulP_v]<rank[ulP_u]){
            parent[ulP_v]=ulP_u;
        }
       else if(rank[ulP_v]>rank[ulP_u]){
            parent[ulP_u]=ulP_v;
        }
        else{
             parent[ulP_u]=ulP_v;
             rank[ulP_v]++;
        }
    }
    void FindUnionBySize(int u,int v){
        int ulP_u=FindUParent(u);
        int ulP_v=FindUParent(v);
        if(ulP_v==ulP_u)return;
        if(rank[ulP_v]<rank[ulP_u]){
            parent[ulP_v]=ulP_u;
            size[ulP_u]+=size[ulP_v];
        }
       
        else{
            parent[ulP_u]=ulP_v;
            size[ulP_v]+=size[ulP_u];
        }
    }
};
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            ds.FindUnionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:stoneNodes){
            if(ds. FindUParent(it.first)==it.first)cnt++;
        }
        return n-cnt;
    }
};
