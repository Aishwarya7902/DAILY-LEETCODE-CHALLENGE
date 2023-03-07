PROBLEM:https://leetcode.com/problems/minimum-time-to-complete-trips/description/
VIDEO:

/*
METHOD 1:
BLOG:https://leetcode.com/problems/minimum-time-to-complete-trips/solutions/1802431/java-c-python-detailed-explanation-with-intuition-o-nlog-k-binary-search-clean-concise/?orderBy=most_votes

Maximum possible time = ~10^14 (from worst case constraints)

Due to this we cannot iterate on time. It will give TLE.

Intution: If we know total time of journey, then we can get how many trips each bus made.

Lets me illustrate this with an example:

Eg: trip_time= 15, time=[1, 2, 5]
No. of trips made by bus 0: 15/1 = 15
No. of trips made by bus 1: 15/2 = 7 (not 7.5 complete trips are 7)
No. of trips made by bus 2: 15/5 = 3

And we can add them all to get total no of trips made by all buses = 15+7+ 3 = 25

Total time of trip lies between 1 and 10^14 (acc to worst case constraints)
Explanation:
assume there is just one bus
when time[i]=1 & totalTrips=1 : time_of_trip= 1
when time[i]= 10^7 & totalTrips=10^7 : time_of_trip= 10^7 * 10^7 = 10^14

Time of trip lies in this range. And as time increases, no of trips increases.
So there will be a time where the no of trips will become just >= totalTrips.
We just need to binary search that time.

Time Complexity Analysis:
Time: O(N log (K)) : where N is no of buses & K is 10^14 (range of binary search)
Space: O(1) : No extra space used.
*/
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
      long long ansTillNow=-1;
      long long left=1,right=1e14;
      while(left<=right){
          long long mid=left+(right-left)/2;
          long long curr_trips=0;
          for(int t:time){
              curr_trips+=mid/t;
          }
          if(curr_trips>=totalTrips){
              ansTillNow=mid;
              right=mid-1;

          }
          else
           left=mid+1;
      }
      return ansTillNow;  
    }
};
