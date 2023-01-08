PROBLEM:https://leetcode.com/problems/max-points-on-a-line/
VIDEO:https://www.youtube.com/watch?v=AzER0wuL0QY

/*
TC: O(N^3)
SC: O(1)
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int n=points.size();
      int maxPoint=1;
      for(int i=0;i<n;i++){
          int x1=points[i][0];
          int y1=points[i][1];
          for(int j=i+1;j<n && j!=i;j++){
              int x2=points[j][0];
              int y2=points[j][1];
              
              int cnt=2;
              for(int k=0;k<n && k!=i && k!=j ;k++){
                  int x3=points[k][0];
                  int y3=points[k][1];
                  if((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1))cnt++;
              }
              maxPoint=max(maxPoint,cnt);
          }
      } 
      return maxPoint; 
    }
};

/*
OPTIMISATION- without atan2 function
TC:O(N^2)
SC:O(N)
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1)
            return 1;
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            
            unordered_map<string, int> mp;
            
            for(int j = 0; j<n; j++) {
                
                if(i == j) continue;
                
                auto dy = points[j][1] - points[i][1];
                auto dx = points[j][0] - points[i][0];
                auto gcd = __gcd(dy, dx);
                
                string key = to_string(dy/gcd) + "_" + to_string(dx/gcd);
                
                mp[key]++;
                
            }
            
            for(auto &it : mp) {
                result = max(result, it.second+1);
            }
        }
        
        return result;
    }
};

/*
using atan2
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int n=points.size();
      if(n==1)return 1;
      int result=0;
      for(int i=0;i<n;i++){
          unordered_map<double,int>mp;
          for(int j=0;j<n;j++){
              if(i==j)continue;
            double dy=points[j][1]-points[i][1];
            double dx=points[j][0]-points[i][0];
            auto theta=atan2(dy,dx);
            mp[theta]++;
          }
          for(auto &it:mp){
              result=max(result,it.second+1);
          }
      }
      
      return result; 
    }
};
Console


