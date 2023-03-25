PROBLEM:https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
VIDEO:
BLOG:

/*
MY INITIAL APPROACH
INTUITION 🔥
what i did was:
1.for every node run a dfs and pass a new visited array for it's dfs call
2.after coming from that dfs call
check how many nodes u could not visit in the vis array
but since the question asks us that we have to count only
unique pairs
so what we can do is na
that lets says u start making dfs calls from i=0 to i=n-1
hence ,it means ...lets say 0 could not reach 1
hence cnt++

now when we make dfs call for 1 then it will say that 
i cant visit 0 then again we will do cnt++

but we dont have to count it again
.....so we will increase our cnt only if for current call
that  node is greater.............for eg ...for 1 ....
0 could not be visited ....it can be clearly seen from visited
but we will increase cnt only if 0>1 ....coz zero ke dfs call
me to 1 ko already count kar hi chuke hoge na
to wapas se count ni karna....it means previous aane wale node agr visited
ni hain to usko cnt ni karenge coz unhone hame already cnt kar liya hoga

tc:o(n^2)  //tle
sc:o(n) //auxiliary stack space
*/

class Solution {
public:
    void dfs(int src,vector<vector<int>>&graph,vector<bool>&vis){
        vis[src]=1;
        for(auto v:graph[src]){
            if(!vis[v])
             dfs(v,graph,vis);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //making a graph
        vector<vector<int>>graph(n);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        long long cnt=0;
        for(int i=0;i<n;i++){
            vector<bool>vis(n,0);
            dfs(i,graph,vis);
            for(int j=0;j<n;j++){
                if(!vis[j] && j>i)cnt++;
            }
        }
        return cnt;

    }
};


/*
method 2:
tc:o(n)
sc:o(1)  //if we leave space for making graph
*/

class Solution {
public:
    int dfs(int src,vector<vector<int>>&graph,vector<bool>&vis){
        int cnt=1;
        vis[src]=1;
        for(auto v:graph[src]){
            if(!vis[v])
            cnt+= dfs(v,graph,vis);
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //making a graph
        vector<vector<int>>graph(n);
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        long long ans=0;
        long sum=n;
        vector<bool>vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
            long  curr= dfs(i,graph,vis);
             sum-=curr;
             ans+=curr*sum;
            }
                       
            
        }
        return ans;

    }
};
