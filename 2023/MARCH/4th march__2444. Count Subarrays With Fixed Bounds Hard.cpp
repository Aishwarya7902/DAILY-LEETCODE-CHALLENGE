PROBLEM:
VIDEO:

/*
just copied the solution
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res=0;
        bool minFound=false,maxFound=false;
        int  start=0,minStart=0,maxStart=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            //condt1
            if(num<minK || num>maxK){
                minFound=false;
                maxFound=false;
                start=i+1;
            }

            //condt2
            if(num==minK){
                minFound=true;
                minStart=i;
            }
            //cond3
            if(num==maxK){
                maxFound=true;
                maxStart=i;
            }
            if(minFound && maxFound){
                res+=(min(minStart,maxStart)-start+1);
            }

        }
        return res;
    }
};
