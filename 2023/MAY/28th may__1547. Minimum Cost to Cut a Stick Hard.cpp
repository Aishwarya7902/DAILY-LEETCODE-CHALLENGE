VIDEO :https://www.youtube.com/watch?v=x4cRwVEFwHc&t=261s

class Solution {
public:
    int t[103][103];
    int solve(vector<int>& cuts,int l, int r){
        if(r-l<2)return 0;
        int result=INT_MAX;
        //lth index =starting point of stick
        //rth index=ending point of stick
        if(t[l][r]!=-1)return t[l][r];

        for(int index=l+1;index<=r-1;index++){
            int cost=(cuts[r]-cuts[l])
                            +
                     solve(cuts,l,index)
                             +
                     solve(cuts,index,r);
            result=min(cost,result);
        }
        return t[l][r]=result;

    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));
        cuts.insert(begin(cuts),0);//starting point of stick
        cuts.push_back(n); // end point of stick

        //length of stick =cuts[r]-cuts[l]
        memset(t,-1,sizeof(t));

        return solve(cuts,0,cuts.size()-1);

    }
};
