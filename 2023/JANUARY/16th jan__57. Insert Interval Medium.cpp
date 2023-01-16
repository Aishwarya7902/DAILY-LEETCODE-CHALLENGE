PROBLEM:https://leetcode.com/problems/insert-interval/
VIDEO (MAZHAR BHAIYA) : https://www.youtube.com/watch?v=XXaVIDIbUn4

/*
naive soln (TLE)
tc:o(n^2)
sc:o(1)
*/

#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        while(i<intervals.size()){
            //condition 1 ...if end of current interval < start of newInterval ,it means newInterval kahin aage jake merge hoga so kuch ni karo bas tum aage badh jao
            if(intervals[i][1]<newInterval[0])
             i++;
            
            //condition 2....if end of newInterval < start of current interval....it means newInterval ko merge karne ki bari  aa gai
            else if(newInterval[1]<intervals[i][0]){
                intervals.insert(intervals.begin()+i,newInterval);
                return intervals;
            }
            //condition 3 ...overlap karne ki bari
            else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
                intervals.erase(intervals.begin()+i);

            }
            
        }
        intervals.push_back(newInterval);
        return intervals;

    }
};

/*
OPTIMISATION
TC:O(N)
SC:O(N)
*/

#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        int n=intervals.size();
        vector<vector<int>>ans;
        while(i<n){
            //condition 1 ...if end of current interval < start of newInterval ,it means newInterval kahin aage jake merge hoga so kuch ni karo bas tum aage badh jao
            if(intervals[i][1]<newInterval[0]){
             ans.push_back(intervals[i]);
             
            }
            
            //condition 2....if end of newInterval < start of current interval....it means newInterval ko merge karne ki bari  aa gai
            else if(newInterval[1]<intervals[i][0]){
                break;
            }
            //condition 3 ...overlap nikalne ki bari 
            else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
                //intervals.erase(intervals.begin()+i);

            }
            i++;
            
        }
        ans.push_back(newInterval);
        while(i<n){
          ans.push_back(intervals[i]);
           i++; 
        }
        return ans;

    }
};
