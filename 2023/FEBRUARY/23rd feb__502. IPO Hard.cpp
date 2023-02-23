PROBLEM:https://leetcode.com/problems/ipo/description/
VIDEO (BEST...APPROACH):https://www.youtube.com/watch?v=Q5K6vRDs2k4
CODE:https://www.youtube.com/watch?v=m4mwEPsCJvg&t=66s

/*
tc:
sc:
*/

class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.second!=b.second){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>project(n);
        for(int i=0;i<n;i++)
         project[i]={profits[i],capital[i]};
        sort(project.begin(),project.end(),cmp);
        int i=0;
        priority_queue<int>pq;
        while(k--){
            while(i<n && project[i].second<=w){
                pq.push(project[i].first);
                i++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
