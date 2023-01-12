PROBLEM:https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
VIDEO(MAZHAR BHAIYA): https://www.youtube.com/watch?v=4seuiuW8c0o

/*
NAIVE SOLUTION :giving tle
PSEUDO CODE:
1.for every node call bfs
2.in bfs if its label is same as parent label cnt++
3.ans[i]=cnt
4.repeat the above steps for every node

tc:o(n^2) //coz for every node we are traversing the whole tree
sc:
*/

class Solution {
private:
int bfs(unordered_map<int,vector<int>>&adj,int node,char label,string labels){
    int cntSame=0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
       int curr=q.front();
       q.pop();
       if(labels[node]==label)cntSame++;
       for(auto &child:adj[node]){
           if(child==node)continue;
           q.push(child);
       }

    }
    return cntSame;
}
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //make graph ready
        unordered_map<int,vector<int>>adj;
        for(auto &vect:edges){
            int u=vect[0];
            int v=vect[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //take  an ans vector
        vector<int>ans(n,0);
       //call bfs for every node
       for(int i=0;i<n;i++){
           int res=bfs(adj,i,labels[i],labels);
           ans[i]=res;
       }
       //return ans
       return ans;
        
    }
};



/*
method 2
*/

class Solution {
private:
vector<int> dfs(unordered_map<int,vector<int>>&adj,int curr,int parent,vector<int>& ans,string &labels){
    vector<int> my_count(26,0);
    char mylabel=labels[curr];
    my_count[mylabel-'a']=1;
    for(int &child:adj[curr]){
        if(child==parent)continue;
        vector<int> child_count(26,0);
         child_count=dfs(adj,child,curr,ans,labels);
         for(int i=0;i<26;i++){
             my_count[i]+=child_count[i];
         }
    }
    ans[curr]=my_count[mylabel-'a'];
    return my_count;
}
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //make graph ready
        unordered_map<int,vector<int>>adj;
        for(auto &vect:edges){
            int u=vect[0];
            int v=vect[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //take  an ans vector
        vector<int>ans(n,0);
       //call dfs for every node
       dfs(adj,0,-1,ans,labels);
       //return ans
       return ans;
        
    }
};
