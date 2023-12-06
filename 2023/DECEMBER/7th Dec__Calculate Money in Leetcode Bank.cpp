PROBLEM:https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2023-12-06
VIDEO:https://www.youtube.com/watch?v=TAmv6Csq3Ss
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int result=0;
        int monday_money=1;
        while(n>0){
            int money=monday_money;
            for(int day=1;day<=min(n,7);day++){
                result+=money;
                money++;
            }
            n-=7;
            monday_money++;
        }
        return result;
    }
};
