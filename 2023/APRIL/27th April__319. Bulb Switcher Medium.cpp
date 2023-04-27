problem:https://leetcode.com/problems/bulb-switcher/description/
video :
(aryan mittal):https://www.youtube.com/watch?v=byFPYruQl2s

/*
tc:
sc:
// states which have odd no of factors then the last state will be in on state
//perfect square will have odd no of factors
*/

class Solution {
public:
    int bulbSwitch(int n) {
        return int(sqrt(n));   
    }
};
