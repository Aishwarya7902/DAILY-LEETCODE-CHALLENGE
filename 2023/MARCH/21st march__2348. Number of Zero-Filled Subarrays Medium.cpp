PROBLEM:https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
VIDEO(ARYAN MITTAL.....SUCH AN AWESOME EXPLANATION MAN):https://www.youtube.com/watch?v=Bel6VXzcu4w&t=1s
BLOG:https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/3322024/image-explanation-2-pointer-3-other-approaches-c-java-python/?orderBy=most_votes

/*
READ THE BLOG AS WELL AS SEE THE VIDEO OF ARYAN...U WILL UNDERSTAND EVERYTHING
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0;
        int n=nums.size();
        for(int i=0,j=0;i<n;++i){
            if(nums[i]!=0)
             j=i+1;
            cnt+=i-j+1;

            // here u might ask why are we adding in cnt for non zero elements....actually they are gonna reduce to zero
            // if we rearrange...formula becomes
            // cnt+=i+1-j.....so for non zero elements we are doing j=i+1 ....and hence cnt+=i+1-j....here j=i+1 ....hence it will add 0 to count
        }
        return cnt;
    }
};
