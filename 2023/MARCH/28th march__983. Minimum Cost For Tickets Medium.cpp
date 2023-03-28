PROBLEM:https://leetcode.com/problems/minimum-cost-for-tickets/
BLOG : 
I.(BEST)
  https://leetcode.com/problems/minimum-cost-for-tickets/solutions/630868/explanation-from-someone-who-took-2-hours-to-solve/?orderBy=most_votes

VIDEO:

/*
RECURSION
TC:3^N
SC:
step1 : understand the problem
here we are given days and cost of passes for 1 day pass, week pass, month pass, "pass means , once you buy it is valid for that some period of time which means free travel during that period"

step 2: logic building and deriving recurence relation

1st sub step : asking questions
when we buy pass what should we think ?
we should think like, what pass should i buy today ?
should i buy pass of one day , week or month pass ?

2nd sub step : Ariving at recurence relation
if i buy one month pass , then i would be able to travel for next 30 days for free, then my cost will be 30 day pass cost + cost for remaining days after 30 day
if i buy one week pass , then i would be able to travel for next 7 days for free, then my cost will be 7 day pass cost + cost for remaining days after 30 day
if i buy 1 day pass ....... ("you get it");

so we can skip to next day OR , next week OR next month ,
so cost for i would total pay today is going to be ? ... ?

# a = cost[one day pass] + cost of next day
# b = cost[ week pass ] + cost of next day after week
# c = cost[ month pass ] + cost of next day after month
ie we can skip 1, 7, or 30 days ;
cost = min( a , b , c )

here is 1st solution using recursion ( TLE )
*/

#include<bits/stdc++.h>
class Solution {
public:
    int helper(vector<int>& days, vector<int>& costs,int indx) {
        int n=days.size();
        if(indx>=n)return 0;
        int cost_day=costs[0]+helper(days,costs,indx+1);
        int i;
        for(i=indx;i<n && days[i]<days[indx]+7;i++);//skip till 7 days

        int cost_week=costs[1]+helper(days,costs,i);
         
         for(i=indx;i<n && days[i]<days[indx]+30;i++);//skip till 30 days
        int cost_month=costs[2]+helper(days,costs,i);
        return min({cost_day, cost_week , cost_month  });
         

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return helper(days,costs,0);
    }
};
