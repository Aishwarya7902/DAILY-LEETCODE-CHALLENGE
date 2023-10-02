Problem:https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/?envType=daily-question&envId=2023-10-02
video(MIK BHAIYA):https://www.youtube.com/watch?v=8jlP3D1Dnj4



/*
  tc:o(n)
  sc:o(1)
  */

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int alice=0;
        int bob=0;
        for(int i=1;i<n-1;i++){
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1]){
                if(colors[i]=='A')alice++;
                else
                 bob++;
            }
        }
        return alice>bob;
    }
};
