PROBLEM:https://leetcode.com/problems/count-all-possible-routes/description/
VIDEO:https://www.youtube.com/watch?v=qppd8vx0vK4

class Solution {
public:
    int t[101][201];
    const int MOD=1e9+7;
    int n;
int solve(vector<int>& locations, int curr_indx, int finish, int fuel){
    if(fuel<0)return 0;
    if(t[curr_indx][fuel]!=-1)return t[curr_indx][fuel];
    int ans=0;
    if(curr_indx==finish){
        ans++;
    }
    for(int j=0;j<n;j++){
        if(curr_indx!=j){
            int remaining_fuel=fuel-abs(locations[curr_indx]-locations[j]);
            ans=(ans+solve(locations,j,finish,remaining_fuel))%MOD;
        }
    }
    return t[curr_indx][fuel]=ans;
}
int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       n=locations.size();
       memset(t,-1,sizeof(t));
       return solve(locations,start,finish,fuel); 
    }
};
