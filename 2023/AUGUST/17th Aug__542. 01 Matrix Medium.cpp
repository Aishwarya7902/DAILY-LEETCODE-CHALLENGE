PROBLEM :https://leetcode.com/problems/01-matrix/description/

VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=gu2MD0mpy9w

/*
  BRUTE FORCE

  for every cell if it is a zero then ans will be zero for that cell ....but if it is one then run bfs for that cell to find min distance from nearest zero

since we are visiting each and every cell .......hence (m*n) cells we have to visit in total........and in worst case if that cell is 1 we will have to visit every cell
to run bfs 
hence in worst case TC is : O((m*n)*(m*n))

  */




/*
  better

  run two for loops......if that cell is a zero push in queue

 now run bfs
TC :O(m*n)
  */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m,n;
        m=mat.size();
        n=mat[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        vector<vector<int>>direction{{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(auto &dir:direction){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && result[new_i][new_j]==-1){
                    result[new_i][new_j]=result[i][j]+1;
                    q.push({new_i,new_j});
                }
            }

        }
        return result;
    }
};
