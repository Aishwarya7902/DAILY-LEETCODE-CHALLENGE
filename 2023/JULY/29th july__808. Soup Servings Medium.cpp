PROBLEM :https://leetcode.com/problems/soup-servings/description/
VIDEO: https://www.youtube.com/watch?v=BiA4x5Gj7io

class Solution {
public:
    vector<pair<int,int>>serves{{100,0},{75,25},{50,50},{25,75}};
    vector<vector<double>>t;
    double solve(double A,double B){
        if(A<=0 && B<=0)
         return 0.5;
        if(A<=0)
         return 1;
        if(B<=0)
         return 0;
        if(t[A][B]!=-0.1)return t[A][B];
        double prob=0.0;
        for(auto &p:serves){
            double A_taken=p.first;
            double B_taken=p.second;
            prob+=solve(A-A_taken,B-B_taken);

        }
        return t[A][B]=0.25*prob;
    }
    double soupServings(int n) {
        if(n>=4000)
         return 1;
        t.resize(n+1,vector<double>(n+1,-0.1));
      return solve(n,n);  
    }
};
