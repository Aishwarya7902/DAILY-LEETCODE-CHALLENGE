PROBLEM:https://leetcode.com/problems/stone-game-iii/description/
VIDEO:(MIK BHAIYA) https://www.youtube.com/watch?v=KI8suf35r38
/*
recursion + memo
tc: o(n) //memo
sc: O(n)
*/

class Solution {
public:
    int n;
    vector<int>t;
    int solve(vector<int>& s,int i){
        if(i>=n)return 0;
        if(t[i]!=-1)return t[i];
        int result=s[i]-solve(s,i+1);
        if(i+1<n)
        result=max(result,s[i]+s[i+1]-solve(s,i+2));
        if(i+2<n)
        result=max(result,s[i]+s[i+1]+s[i+2]-solve(s,i+3));
        
        return t[i]=result;
    }
    string stoneGameIII(vector<int>& stones) {
        n=stones.size();
        t.resize(n+1,-1);
        int diff=solve(stones,0);//Alice-Bob
        if(diff<0)
         return "Bob";
        else if(diff>0)
         return "Alice";
        else
         return "Tie";

        
    }
};

/*
BOTTOM UP 
TC:O(N)
SC:O(N)
*/

class Solution {
public:
    int n;
    
    
    string stoneGameIII(vector<int>& s) {
        n=s.size();
        vector<int> t(n+1);
        for(int i=n-1;i>=0;i--){
            
            t[i]=s[i]-t[i+1];

            if(i+2<=n)
            t[i]=max(t[i],s[i]+s[i+1]-t[i+2]);

            if(i+3<=n)
            t[i]=max(t[i],s[i]+s[i+1]+s[i+2]-t[i+3]);
        }
        int diff=t[0];//Alice-Bob
        if(diff<0)
         return "Bob";
        else if(diff>0)
         return "Alice";
       
         return "Tie";

        
    }
};

/*
SPACE OPTIMISATION
TC:O(N)
SC:O(1)
*/
class Solution {
public:
    int n;
    
    
    string stoneGameIII(vector<int>& s) {
        n=s.size();
        int a=0;//t[i+1]
        int b=0;//t[i+1]
        int c=0;//t[i+2]
        int result=INT_MAX;
        for(int i=n-1;i>=0;i--){
            
            result=s[i]-a;

            if(i+2<=n)
            result=max(result,s[i]+s[i+1]-b);

            if(i+3<=n)
            result=max(result,s[i]+s[i+1]+s[i+2]-c);
            c=b;
            b=a;
            a=result;
        }
        int diff=result;//Alice-Bob
        if(diff<0)
         return "Bob";
        else if(diff>0)
         return "Alice";
       
         return "Tie";

        
    }
};
