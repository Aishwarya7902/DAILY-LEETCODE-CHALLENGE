PROBLEM:https://leetcode.com/problems/design-browser-history/description/
VIDEO:
BLOG:

/*
METHOD 1:
TC:Since this is a design question, we need to think about how many calls of such implementation will be made. However, let's calculate the complexities of 1 instance.

Time: constructor & visit() are constant in terms of time, we don't traverse anything, just push to stack. But if we look at back() & forward(), 
 it is obvious that we traverse our stacks, so time complexity is O(n + m), where m is the size of history & n is the size of future.

SC:we are initializing 2 stacks and the sizes of these stacks are differ due to back & forward calls, so space complexity is the same as time: O(n + m)
*/

class BrowserHistory {
public:
    stack<string>history;
    stack<string>future;

    BrowserHistory(string homepage) {
        history.push(homepage);
        future=stack<string> ();
    }
    
    void visit(string url) {
        history.push(url);
        future=stack<string> ();
    }
    
    string back(int steps) {
      while(steps>0 && history.size()>1){
          future.push(history.top());
          history.pop();
          steps--;
      }  
      return history.top();
    }
    
    string forward(int steps) {
       while(steps>0 && future.size()>0){
         history.push(future.top());
          future.pop();
          steps--;
      }  
      return history.top(); 
    }
};
