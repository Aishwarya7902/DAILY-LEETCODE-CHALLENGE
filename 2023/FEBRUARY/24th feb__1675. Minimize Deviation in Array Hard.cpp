PROBLEM:https://leetcode.com/problems/minimize-deviation-in-array/description/
VIDEO:https://www.youtube.com/watch?v=CP7M1JrBoc8

/*
TC:o(nlogn)
SC:o(n)
pseudo code
1.make every no even
2.find min .....
3.pq top will give max no
4.find diff between min and max obtained from above steps and update ans
5.if max is odd ....just break and return ans
6.else..............max ko min ke kareeb lane ki kosis karo....hence max=max/2
7.put in pq...
8.repeat step 2,3,4,5,6 till pq is not empty
*/


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int m=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                pq.push(nums[i]);
                m=min(m,nums[i]);
            }
            else{
                pq.push(nums[i]*2);
                m=min(m,nums[i]*2);
            }
        }
        int ans=INT_MAX;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            ans=min(ans,top-m);
            if(top%2!=0)
             break;
            m=min(m,top/2);
            pq.push(top/2);
        }
        return ans;
    }
};

