PROBLEM:https://leetcode.com/problems/online-stock-span/
VIDEO: https://www.youtube.com/watch?v=2ECIzYBZ3hI

/*
TC:O(N)
SC:O(N)
*/

class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        while(!st.empty() && st.top().first<=price){
          auto x=st.top();
          st.pop();
          ans+=x.second;
        
        }
      st.push({price,ans});
      return ans;
    }
};
