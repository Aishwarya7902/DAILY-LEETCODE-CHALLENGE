PROBLEM:https://leetcode.com/problems/can-place-flowers/description/
BLOG:https://leetcode.com/problems/can-place-flowers/solutions/1698771/c-java-python-2-simple-solutions-image-explanation-beginner-friendly/?orderBy=most_votes
VIDEO:

/*
METHOD 1
TC
SC
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
       int size=flowerbed.size();
       if(n==0)return true;
       for(int i=0;i<size;i++){
           if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==size-1 || flowerbed[i+1]==0)){
               --n;
               if(n==0)return true;
               flowerbed[i]=1;
           }
       }
       return false;
    }
};
