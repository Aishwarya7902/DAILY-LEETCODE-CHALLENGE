PROBLEM:https://leetcode.com/problems/find-the-town-judge/description/
VIDEO:https://www.youtube.com/watch?v=ottPfSr3xls&lc=UgzfX5Nyg7Hk93uzp0h4AaABAg

/*
TC:O(N)
SC:O(2N)
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<int>indegree(n+1);
       vector<int>outdegree(n+1);
       for(auto it:trust){
           int u=it[0];
           int v=it[1];
           indegree[v]++;
           outdegree[u]++;
       }
    for(int i=1;i<=n;i++){
        if(indegree[i]==n-1 && outdegree[i]==0)return i;
    }
    return -1;
    }
};
